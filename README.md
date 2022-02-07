## About the Project
This is an introductionary project to get familiar with the C++ syntax and methodology.

## Getting Started

### Installation
```
git clone https://github.com/henk-vd-brink/cpp-heat_equation.git
cd cpp-heat_equation
```

### Build
```
make
```

### Run
```
./bin/main
```

To see a visualisation in 'visualisation/figures/comparison.png' (only works for 1D atm).
```
python visualisation/plot.py
```

## Structure
```bash
.
├── Makefile
├── README.md
├── bin
│   └── main
├── data
│   ├── cgSolution.txt
│   └── exactSolution.txt
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
