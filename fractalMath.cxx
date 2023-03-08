#include "fractalMath.hxx"

bool escript::Mandelbrot::isInSet(std::complex<double> number) {
    constexpr int iterationCount = 50;
    //It is cheaper to compare the squared value with std::norm instead of comparing the value with std::abs
    constexpr double maxMagnitude = 10*10;
    std::complex<double> numberAfterIterating = getIteratedValue(number, iterationCount);

    return std::norm(numberAfterIterating) <= maxMagnitude;
}

std::complex<double> escript::Mandelbrot::getIteratedValue(std::complex<double> number, int iterationCount) {
    std::complex<double> currentValue = std::pow(number, 2) + number;
    for(int i = 0; i < iterationCount; ++i) {
        currentValue = std::pow(currentValue, 2);
        currentValue += number;
    }
    return currentValue;
}

int escript::Mandelbrot::iterationsUntilEscape(std::complex<double> number, int maxIterations) {
    std::complex<double> currentValue = std::pow(number, 2) + number;
    int iterations = 1;
    for(; iterations < maxIterations && std::norm(currentValue) <= 2*2; ++iterations) {
        currentValue = std::pow(currentValue, 2);
        currentValue += number;
    }
    return iterations;
}