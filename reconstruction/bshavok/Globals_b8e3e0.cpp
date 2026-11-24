// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: SolveWithSolver.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/internal/collide/mopp/machine/hkpmoppkdopgeometriesvirtualmachine.cpp:68
// 0xb8e3e0 SolveWithSolver
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/havok/physics/internal/collide/mopp/machine/hkpmoppkdopgeometriesvirtualmachine.cpp:85
#include "Globals_b8e3e0.h"

void SolveWithSolver(void* a, void* b, void* c)
{
    E5CF70Solver solver;
    solver.solve(a, b, c);
}
