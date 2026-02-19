#ifndef OVEZOV_ARC_HPP
#define OVEZOV_ARC_HPP

#include <cmath>

/**
 * Calculates the length of a circular arc using the Ovezov Equation.
 * * Formula: P = (2 * (h^2 + 0.25 * L^2) / h) * arcsin(h / sqrt(h^2 + 0.25 * L^2))
 * * @param L The length of the chord (linear distance).
 * @param h The height (sagitta) of the arc segment.
 * @return The length of the arc. Returns L if h is 0.
 */
inline double getOvezovArcLength(double L, double h) {
    if (h <= 0.0) {
        return L;
    }
    
    // Pure analytical implementation of the Ovezov Equation
    return (2.0 * (h * h + 0.25 * L * L) / h) * std::asin(h / std::sqrt(h * h + 0.25 * L * L));
}

#endif // OVEZOV_ARC_HPP
