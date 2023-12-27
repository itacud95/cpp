

#include <iostream>
struct Foo {
    ~Foo() { std::cout << "--Foo\n"; }
};
struct Bar {
    ~Bar() { std::cout << "--Bar\n"; }
    Foo foo;
    Foo foo2;
};

int main() {
    Bar bar;
}