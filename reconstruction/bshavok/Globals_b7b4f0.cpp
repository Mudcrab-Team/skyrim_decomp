// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpBroadPhaseListener::removeCollisionPair_140A9CF00.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/dynamics/world/util/broadphase/hkpentityentitybroadphaselistener.cpp:325
// 0xb7b4f0 hkpBroadPhaseListener::removeCollisionPair_140A9CF00
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/havok/physics/dynamics/world/util/broadphase/hkpentityentitybroadphaselistener.cpp:291
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/dynamics/world/util/broadphase/hkpentityentitybroadphaselistener.cpp:302
// Adapted helpers: getOwner
// CI hash: 0xb7b4f0 ?removeCollisionPair_140A9CF00@hkpBroadPhaseListener@@QEAAXAEAUD10860HandlePair@@@Z
#include "Globals_b7b4f0.h"

void hkpBroadPhaseListener::removeCollisionPair_140A9CF00(D10860HandlePair& pair)
{
    D10860Collidable* collA = pair.m_kPointA->getOwner();
    D10860Collidable* collB = pair.m_kPointB->getOwner();
    D10860Agent* agent = FindEntryValue(collA, collB);
    if (agent)
        Func00cc10b0(agent);
}
