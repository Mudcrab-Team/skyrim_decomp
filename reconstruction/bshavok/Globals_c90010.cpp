// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00d2e970.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp:363
// 0xc90010 Func00d2e970
#include "Globals_c90010.h"

void Func00d2e970(void* bodyA, void* bodyB, void* arg3, void* orig_collector)
{
    Collector c;
    c.collector = orig_collector;
    c.flip = 0;
    c.vtable = &Data010ce81c;
    Func00d312f0(bodyB, bodyA, arg3, &c);
}
