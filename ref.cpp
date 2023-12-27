#include <iostream>
#include <memory>
#include <thread>

struct Foo {
    void Hello() { std::cout << "Hello\n"; }
    void operator()() { std::cout << "operator()\n"; }
};

int main() {
    std::shared_ptr<Foo> foo = std::make_shared<Foo>();
    foo->Hello();
    auto handle = std::thread(std::ref(*foo));
    handle.join();
}

