#include <iostream>
#include <cmath>

// Function to calculate the value of f(x)
double f(double x) {
    return 0.2 * x * x; // Replace with your own function
}

// Function to calculate the integral area using the trapezoidal rule
double calculateIntegralArea(double a, double b, int numIntervals) {
    double h = (b - a) / numIntervals; // Interval width
    double sum = 0.0;

    // Calculate the sum of areas of trapezoids
    for (int i = 1; i < numIntervals; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    // Add the areas of the first and last intervals
    sum += (f(a) + f(b)) / 2.0;

    // Multiply by the interval width to get the integral area
    double integralArea = h * sum;
    return integralArea;
}

int main() {
    double a = 1.0; // Lower limit of integration
    double b = 4.0; // Upper limit of integration
    int numIntervals = 1000; // Number of intervals (higher value = more accurate result)

    double integralArea = calculateIntegralArea(a, b, numIntervals);
    std::cout << "Integral Area: " << integralArea << std::endl;

    return 0;
}
