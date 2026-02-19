# Ovezov-Arc-Equation

## Precision Arc Length Calculation via Chord and Sagitta

### 🎯 Overview
The **Ovezov-Arc-Equation** is a direct analytical solution for determining the length of a circular arc ($P$) using only two physically measurable parameters: the **Chord ($L$)** and the **Height/Sagitta ($h$)**.

In practical engineering — whether in CNC machining, robotics, or architecture — measuring the radius or locating the center of a circle is often difficult or impossible. This equation provides a "math-to-metal" bridge, allowing for laboratory-grade precision using only field measurements.



### 💡 The Equation
Based on geometric invariants and the principle of similar triangles, the equation expresses arc length ($P$) in a single, atomic step:

$$P = \frac{2(h^2 + 0.25L^2)}{h} \arcsin\left(\frac{h}{\sqrt{h^2 + 0.25L^2}}\right)$$

Where:
* **L** = Chord length (linear distance between arc ends)
* **h** = Height of the segment (Sagitta)
* **P** = Resulting Arc Length

### 🚀 Why Use This?
* **Zero-Radius Dependency:** No need to calculate or know the radius ($R$) or the central angle.
* **Hardware Optimized:** Minimal register usage and fixed execution time (deterministic), which is critical for **Real-Time Systems** and **Microcontrollers** (STM32, Arduino, ESP32).
* **Numerical Stability:** Unlike multi-step methods, this analytical form remains robust even for extremely small $h$ (near-zero curvature), avoiding the precision "drift" common in iterative algorithms.

### 🛠 Practical Implementation

#### Python
```python
import math

def ovezov_arc_length(L, h):
    """
    Calculates arc length directly from chord L and height h.
    Handles the edge case of a straight line (h=0).
    """
    if h == 0: 
        return float(L)
    
    # Direct implementation of the Ovezov Equation
    return (2 * (h**2 + 0.25 * L**2) / h) * math.asin(h / math.sqrt(h**2 + 0.25 * L**2))

# Example: Chord = 100mm, Height = 10mm
result = ovezov_arc_length(100, 10)
print(f"Arc Length: {result:.8f} mm")
