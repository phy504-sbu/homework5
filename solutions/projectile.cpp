#include <iostream>
#include <cmath>
#include <vector>

struct Coords {
    double t{};
    double x{};
    double y{};
};


// gravitational acceleration
const double g{-9.81};

int main() {

    double v{};
    std::cout << "enter initial velocity magnitude (m/s): ";
    std::cin >> v;

    double theta{};
    std::cout << "enter angle (degrees): ";
    std::cin >> theta;

    // convert it to radians

    theta *= M_PI/180;

    double dt{};
    std::cout << "enter time interval: ";
    std::cin >> dt;

    // compute the x and y components of the velocity

    double vx0 = v * std::cos(theta);
    double vy0 = v * std::sin(theta);

    std::vector<Coords> trajectory{};

    // initial coords:

    Coords c; 
    c.x = 0.0;
    c.y = 0.0;
    c.t = 0.0;

    trajectory.push_back(c);

    while (c.y >= 0.0) {

        c.t += dt;
        c.x = vx0 * c.t;
        c.y = vy0 * c.t + 0.5 * g * c.t * c.t;

        trajectory.push_back(c);
    }

    for (auto c : trajectory) {
        std::cout << "t = " << c.t << ": x = " << c.x << " y = " << c.y << std::endl;
    }

}