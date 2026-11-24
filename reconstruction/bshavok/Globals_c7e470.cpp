// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: ApplyTransformToTarget.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp:105
// 0xc7e470 ApplyTransformToTarget
#include "Globals_c7e470.h"

void ApplyTransformToTarget(Holder* apFirst, Holder* apSecond, ValueSource* apValue, void* apContext)
{
    Transform kTransform(apSecond->m_pData, apFirst->m_pData);
    apFirst->m_pFlagTarget->Apply(&kTransform, apValue->m_fAmount, apContext);
}
