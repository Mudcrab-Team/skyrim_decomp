// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpSphereSphereAgent::Routine140BA59F0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp:34
// 0xc81a90 hkpSphereSphereAgent::Routine140BA59F0
// CI hash: 0xc81a90 ?Routine140BA59F0@hkpSphereSphereAgent@@QEAAXPEAX@Z
#include "Globals_c81a90.h"

void hkpSphereSphereAgent::Routine140BA59F0(void* arg)
{
    if (unkC != 0xffff)
    {
        unk8->Release(unkC, arg);
        unkC = 0xffff;
    }
    delete this;
}
