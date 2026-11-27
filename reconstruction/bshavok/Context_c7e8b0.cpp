// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Context::Func00d2edd0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp:280
// 0xc7e8b0 Context::Func00d2edd0
#include "Context_c7e8b0.h"

void Context::Func00d2edd0(void* first, void* second, void* third, void* fourth)
{
    hkpSymmetricAgentFlipCollector collector;
    collector.threshold = Data0104da48;
    collector.object = fourth;
    Func00d43880(second, first, third, &collector);
}
