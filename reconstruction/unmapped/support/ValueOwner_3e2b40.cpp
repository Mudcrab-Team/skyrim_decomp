// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_004021b0::ValueOwner::Func004021b0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00400000_o2.cpp:1523
// 0x3e2b40 f3m_004021b0::ValueOwner::Func004021b0
#include "ValueOwner_3e2b40.h"

namespace f3m_004021b0 {
void ValueOwner::Func004021b0(const StoredValue* supplied)
{
    if (supplied)
    {
        value.Func005ae2d0(supplied, 0);
    }
    else
    {
        StoredValue empty;
        value.Func005ae2d0(&empty, 0);
    }
}
}
