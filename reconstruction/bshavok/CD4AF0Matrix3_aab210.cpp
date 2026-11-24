// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: CD4AF0Matrix3::Func00cd4af0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/math/matrix/hkmatrix3.cpp:39
// 0xaab210 CD4AF0Matrix3::Func00cd4af0
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/havok/common/base/math/matrix/hkmatrix3.cpp:52
// Adapted helpers: CD4AF0Bool
#include "CD4AF0Matrix3_aab210.h"

CD4AF0Bool CD4AF0Matrix3::Func00cd4af0() const
{
    return m_kColumn0.IsStreamValid() && m_kColumn1.IsStreamValid() && m_kColumn2.IsStreamValid();
}
