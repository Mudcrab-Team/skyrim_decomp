// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00e9e980.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nicollision/nihalfspacebv.cpp:121
// 0xf3dcc0 Func00e9e980
#include "Globals_f3dcc0.h"

bool Func00e9e980(float afValue, D_00e9e980* pContainer, void* a, void* b, void* c)
{
    unsigned int i = 0;
    for (; i < pContainer->m_cnt; ++i)
    {
        void* e = pContainer->m_pp[i];
        if (CallConditionFunction(afValue, e, a, b, c))
        {
            pContainer->m_found = (int)i;
            return true;
        }
    }
    return false;
}
