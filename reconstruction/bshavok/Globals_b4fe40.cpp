// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpPrismaticConstraintData::Routine140A71580.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/dynamics/constraint/bilateral/prismatic/hkpprismaticconstraintdata.cpp:93
// 0xb4fe40 hkpPrismaticConstraintData::Routine140A71580
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/dynamics/constraint/bilateral/prismatic/hkpprismaticconstraintdata.cpp:60
// Adapted helpers: hkBoolD4FD
#include "Globals_b4fe40.h"

hkBoolD4FD hkpPrismaticConstraintData::Routine140A71580() const
{
    return m_kPointA.IsOrthonormal(Data01017d00) && m_kPointB.IsOrthonormal(Data01017d00) && m_kMinimumCorner <= m_kMaximumCorner;
}
