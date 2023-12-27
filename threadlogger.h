#pragma once

#include <cstddef>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <vector>

inline std::string GetColorCodeForThreadId() {
    static std::vector<size_t> colours = {
            31,  // red
            32,  // green
            33,  // yellow
            34,  // blue
            35,  // magenta
            36,  // cyan
    };
    static size_t colorIndex = 0;
    static std::map<size_t, size_t> mapped;

    std::hash<std::thread::id> hasher;
    auto id = std::this_thread::get_id();
    auto threadIdHash = hasher(id);

    auto foo = mapped.try_emplace(threadIdHash, colours[colorIndex]);
    if (bool inserted = foo.second; inserted) {
        colorIndex++;
    }

    size_t color = mapped.find(threadIdHash)->second;

    return "\033[1;" + std::to_string(color) + "m";
}

inline void Log(const std::string& msg) {
    static std::mutex consoleMutex;
    std::lock_guard<std::mutex> lock(consoleMutex);

    std::string colorCode = GetColorCodeForThreadId();
    std::cout << colorCode << msg << " [" << std::this_thread::get_id() << "]"
              << "\033[0m\n";
}
