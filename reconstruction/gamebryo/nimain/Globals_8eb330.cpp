// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: fnv_00e9cb50::hkpCollisionFilter::GetClassType.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nicollision/nihalfspacebv.cpp:163
// 0x8eb330 fnv_00e9cb50::hkpCollisionFilter::GetClassType
#include "Globals_8eb330.h"

namespace fnv_00e9cb50 {
void hkpCollisionFilter::GetClassType(NiStream& stream)
{
    NiObject::LinkObject(stream);
    m_kHalfSpacePlane.LoadBinary(stream);
    m_kCenter.LoadBinary(stream);
}
}
