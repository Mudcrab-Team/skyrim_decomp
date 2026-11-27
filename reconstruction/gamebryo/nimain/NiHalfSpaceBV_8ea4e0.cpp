// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: fnv_00e9cb50::NiHalfSpaceBV::Func00e9cb50.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nicollision/nihalfspacebv.cpp:163
// 0x8ea4e0 fnv_00e9cb50::NiHalfSpaceBV::Func00e9cb50
#include "NiHalfSpaceBV_8ea4e0.h"

namespace fnv_00e9cb50 {
void NiHalfSpaceBV::Func00e9cb50(NiStream& stream)
{
    NiObject::LinkObject(stream);
    m_kHalfSpacePlane.LoadBinary(stream);
    m_kCenter.LoadBinary(stream);
}
}
