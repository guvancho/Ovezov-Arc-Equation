* **Project Name**: Ovezov-Arc-Equation
* **Concept**: A direct analytical solution for calculating arc length ($P$) based on chord ($L$) and height ($h$).

* [![Theory](https://img.shields.io/badge/Documentation-Mathematical_Theory-blue?style=for-the-badge&logo=googlesheets)](./THEORY.md)

* **💡 The Equation**:
  $$P = \frac{2(h^2 + 0.25L^2)}{h} \arcsin\left(\frac{h}{\sqrt{h^2 + 0.25L^2}}\right)$$
  * **L**: Chord length (measurable distance between ends)
  * **h**: Height of the segment (Sagitta)
  * **P**: Resulting Arc Length

### 🚀 Key Advantages

* **Zero-Radius Dependency**: Eliminates the need to locate the circle's center or handle massive radius values in memory.
* **Total Geometric Versatility**:
    * **Near-Flat Lines ($L \gg h$):** Maintains extreme precision (up to $10^{-11}$) where classical methods "flatline" and return zero curvature.
    * **Standard Arcs ($L = h$):** Perfectly handles deep segments (angles $> 180^\circ$) without requiring additional logic or sign checks.
    * **"Needle" Geometries ($L \ll h$):** Remains analytically stable for extreme vertical arcs where height vastly exceeds the base.
* **Numerical Stability**: Effectively bypasses "catastrophic cancellation" errors common in standard $R = \frac{h}{2} + \frac{L^2}{8h}$ calculations.
* **Hardware Optimized**: Extremely lightweight and efficient on the instruction level, making it the ideal choice for **STM32**, **Arduino**, and real-time robotics where CPU cycles and precision are critical.

* **🛠 Practical Implementation**:
    * **Python**:
    ```python
    import math
    def ovezov_arc_length(L, h):
        if h == 0: return float(L)
        return (2 * (h**2 + 0.25 * L**2) / h) * math.asin(h / math.sqrt(h**2 + 0.25 * L**2))

    # Example: Chord = 100, Height = 10
    print(f"Arc Length: {ovezov_arc_length(100, 10):.8f}")
    ```
    * **C++**: [Download ovezov_arc.hpp](./ovezov_arc.hpp)

* **✅ Validation (CAD Benchmarking)**:
    * **Industry Standard**: Tested against **AutoCAD** geometry engine.
    * **Input**: $L = 100$, $h = 10$.
    * **AutoCAD Result**: `102.64569112`
    * **Ovezov Result**: `102.64569112`
    * **Verdict**: 100% precision match up to 8 decimal places.

* **🌍 Applications**: Robotics, CNC trajectory planning, and architectural geometry.
* **📜 License**: MIT
