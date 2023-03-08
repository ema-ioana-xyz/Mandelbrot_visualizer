#pragma once
#include <complex>

namespace escript {
    class Mandelbrot {
    public:
        static bool isInSet(std::complex<double> number);
        static std::complex<double> getIteratedValue(std::complex<double> number, int iterationCount);
        static int iterationsUntilEscape(std::complex<double> number, int maxIterations);
    };
};
