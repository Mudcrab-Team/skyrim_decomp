// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: E9E8C0Array::Func00e9e8c0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nicollision/niunionbv_o2_noo1_nooy_variant.cpp:260
// 0xf3dc00 E9E8C0Array::Func00e9e8c0
// Adapted helpers: GetAt
#include "NiUnionBV_f3dc00.h"

bool E9E8C0Array::Func00e9e8c0(E9E8C0Array* pkOther)
{
    if (pkOther->GetType() != 4)
        return false;
    if (m_kUnsortedGeometryList.GetSize() != pkOther->m_kUnsortedGeometryList.GetSize())
        return false;
    for (unsigned int ui = 0; ui < m_kUnsortedGeometryList.GetSize(); ui++)
    {
        if (m_kUnsortedGeometryList.GetAt(ui)->IsDifferent(pkOther->m_kUnsortedGeometryList.GetAt(ui)))
            return false;
    }
    return true;
}
