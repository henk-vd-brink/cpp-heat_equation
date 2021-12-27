# C++ Solving the N dimensional Heat Equation.

This is an introductionary project to get familiar with the C++ syntax and methodology. 

# Structure
```bash
.
├── Makefile
├── README.md
├── bin
│   └── main
├── data
│   ├── cgSolution.txt
│   └── exactSolution.txt
├── include
├── src
│   ├── Math
│   │   ├── Heat.hpp
│   │   ├── Math.hpp
│   │   ├── Solvers
│   │   │   ├── CGSolver.hpp
│   │   │   ├── ExactSolver.hpp
│   │   │   └── Solvers.hpp
│   │   └── Tensors
│   │       ├── Matrix.hpp
│   │       ├── TensorCalculus
│   │       │   ├── MatrixVectorProduct.hpp
│   │       │   └── TensorCalculus.hpp
│   │       ├── Tensors.hpp
│   │       └── Vector.hpp
│   └── main.cpp
└── visualisation
    ├── figures
    │   └── compare.png
    └── plot.py
```

# Usage 

To to the root folder and:

```bash
make clean && make && ./bin/main
```

For comparison plot (only works for 1D at the moment):
```bash
python visualisation/plot.py
```

See comparison plot in 'visualisation/figures/comparison.png'
