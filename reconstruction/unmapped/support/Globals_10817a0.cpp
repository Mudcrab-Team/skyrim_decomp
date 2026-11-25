// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00925920::bhkRigidBodyT::Func58_140DDB730.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3iso_00925920_o2.cpp:25
// 0x10817a0 f3m_00925920::bhkRigidBodyT::Func58_140DDB730
#include "Globals_10817a0.h"

namespace f3m_00925920 {
Transform* bhkRigidBodyT::Func58_140DDB730(Transform* result) {
    Vector4 rotation;
    methods->translation(this,&result->translation);
    methods->rotation(this,&rotation);
    result->Func00924b40(&rotation);
    return result;
}
}
