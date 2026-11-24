// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: fnv_00e9cb50::NiBezPosKey::LoadBinary.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nicollision/nihalfspacebv.cpp:163
// 0xf8e5f0 fnv_00e9cb50::NiBezPosKey::LoadBinary
#include "NiBezPosKey_f8e5f0.h"

namespace fnv_00e9cb50 {
void NiBezPosKey::LoadBinary(NiStream& stream)
{
    NiObject::LinkObject(stream);
    m_kHalfSpacePlane.LoadBinary(stream);
    m_kCenter.LoadBinary(stream);
}
}
