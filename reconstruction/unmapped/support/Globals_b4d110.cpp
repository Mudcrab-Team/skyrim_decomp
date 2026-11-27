// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_0090cf80::vector_event_0090cf80::hkpEntity::applyLinearImpulseAsCriticalOperation_140A6E850.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00900000_o2.cpp:7477
// 0xb4d110 f3m_0090cf80::vector_event_0090cf80::hkpEntity::applyLinearImpulseAsCriticalOperation_140A6E850
// Adapted helpers: Append, Scaled
#include "Globals_b4d110.h"

namespace f3m_0090cf80 {
namespace vector_event_0090cf80 {
void hkpEntity::applyLinearImpulseAsCriticalOperation_140A6E850(const Point3& point) {
    if(manager && manager->active) {
        Event event(this,point);
        manager->Func00902570(&event);
    } else {
        Func0090b500();
        fallback.Notify(point);
    }
}
}
}
