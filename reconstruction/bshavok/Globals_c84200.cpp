// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00d2e970.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp:363
// 0xc84200 Func00d2e970
// CI hash: 0xc84200 ?Func00d2e970@@YAXPEAX000@Z
#include "Globals_c84200.h"

void Func00d2e970(void* bodyA, void* bodyB, void* arg3, void* orig_collector)
{
    FlipCollector c(orig_collector);
    Func00d312f0(bodyB, bodyA, arg3, &c);
}
