// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: E07510Solver::Func00e07510.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp:501
// 0x112c260 E07510Solver::Func00e07510
#include "E07510Solver_112c260.h"

void E07510Solver::Func00e07510(E07510Input* pInput, void* b, void* c, void* d)
{
    if (pInput->m_type == 1)
        Func00e07070(b, c, d);
    AdjustLimits(pInput, b, c);
}
