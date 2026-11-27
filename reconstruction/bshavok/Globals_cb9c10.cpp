// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00e29250.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/math/matrix/hkmatrix6.cpp:77
// 0xcb9c10 Func00e29250
#include "Globals_cb9c10.h"

void Func00e29250(E29250Matrix6& out, const E29250Matrix6& in)
{
    out.m_iUnknownValue2[0][0].SetFromMatrix(in.m_iUnknownValue2[0][0]);
    out.m_iUnknownValue2[0][1].SetFromMatrix(in.m_iUnknownValue2[1][0]);
    out.m_iUnknownValue2[1][0].SetFromMatrix(in.m_iUnknownValue2[0][1]);
    out.m_iUnknownValue2[1][1].SetFromMatrix(in.m_iUnknownValue2[1][1]);
}
