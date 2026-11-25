// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpRayCollidableFilter::isCollisionEnabled_140AC7400.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/utilities/collide/filter/constrainedsystem/hkpconstrainedsystemfilter.cpp:261
// 0xba59f0 hkpRayCollidableFilter::isCollisionEnabled_140AC7400
// Adapted helpers: hkBoolE46D
#include "Globals_ba59f0.h"

hkBoolE46D hkpRayCollidableFilter::isCollisionEnabled_140AC7400(void* a, void* b)
{
    return !m_pOwningWorld || m_pOwningWorld->m_iFilter.IsCollisionEnabled(a, b).m_cBooleanValue;
}
