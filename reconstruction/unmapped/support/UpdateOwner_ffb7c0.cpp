// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00ab7870::UpdateOwner::Func00ab7870.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00aa0000_o2.cpp:19272
// 0xffb7c0 f3m_00ab7870::UpdateOwner::Func00ab7870
#include "UpdateOwner_ffb7c0.h"

namespace f3m_00ab7870 {
void UpdateOwner::Func00ab7870(float* pfValue, int b)
{
    float saved;
    int a0;
    int a1;
    int a2;
    int a3;
    Func00ab76f0();
    if (m_b8 > 0 || Func00ab70d0())
    {
        m_dc += *pfValue;
        saved = *pfValue;
        *pfValue = m_dc;
        Func0082dcf0(pfValue, b);
        *pfValue = saved;
    }
}
}
