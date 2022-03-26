#include <iostream>
#include <string>

int main() {

    std::string force{"may the force be with you"};

    bool needs_caps = true;
    for (auto it = force.begin(); it < force.end(); ++it) {
        if (needs_caps && *it != ' ') {
            *it = std::toupper(*it);
            needs_caps = false;
            continue;
        }

        if (*it == ' ') {
            needs_caps = true;
        }
    }

    std::cout << force << std::endl;
}