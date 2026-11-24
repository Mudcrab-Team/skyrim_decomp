// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpRayCollidableFilter::isCollisionEnabled_140A928D0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/utilities/collide/filter/constrainedsystem/hkpconstrainedsystemfilter.cpp:261
// 0xb70ec0 hkpRayCollidableFilter::isCollisionEnabled_140A928D0
// Adapted helpers: hkBoolE46D
#include "Globals_b70ec0.h"

hkBoolE46D hkpRayCollidableFilter::isCollisionEnabled_140A928D0(void* a, void* b)
{
    return !m_pOwningWorld || m_pOwningWorld->m_iFilter.IsCollisionEnabled(a, b).m_cBooleanValue;
}
