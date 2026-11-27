// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00cbe750_C::Func00cbe750.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/dynamics/constraint/bilateral/hinge/hkphingeconstraintdata.cpp:209
// 0xb743b0 Func00cbe750_C::Func00cbe750
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/dynamics/constraint/bilateral/hinge/hkphingeconstraintdata.cpp:180
// Adapted helpers: hkBoolCBE7
#include "Func00cbe750_C_b743b0.h"

hkBoolCBE7 Func00cbe750_C::Func00cbe750() const
{
    return m_kPointA.IsOrthonormal(0.001f) && m_kPointB.IsOrthonormal(0.001f);
}
