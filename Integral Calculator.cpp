#include <iostream>
#include <cmath>

double function(double x) {
    // Define the function here
    return x * x;
}

double calculateIntegral(double a, double b, int numIntervals) {
    double h = (b - a) / numIntervals;
    double integral = 0.0;

    for (int i = 0; i < numIntervals; i++) {
        double x1 = a + i * h;
        double x2 = x1 + h;
        double y1 = function(x1);
        double y2 = function(x2);

        integral += (y1 + y2) / 2.0 * h;
    }

    return integral;
}

int main() {
    double a, b;
    int numIntervals;

    std::cout << "Enter the lower bound of the interval: ";
    std::cin >> a;
    std::cout << "Enter the upper bound of the interval: ";
    std::cin >> b;
    std::cout << "Enter the number of intervals: ";
    std::cin >> numIntervals;

    double result = calculateIntegral(a, b, numIntervals);

    std::cout << "The integral is: " << result << std::endl;

    return 0;
}
