#include <iostream>
#include <string>

int main() {

    std::string force{"may the force be with you"};

    bool needs_caps = true;
    for (auto &c: force) {
        if (needs_caps && c != ' ') {
            c = std::toupper(c);
            needs_caps = false;
            continue;
        }

        if (c == ' ') {
            needs_caps = true;
        }
    }

    std::cout << force << std::endl;
}