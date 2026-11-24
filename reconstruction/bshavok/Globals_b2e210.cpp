// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkDynamicClassNameRegistry::registerList.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/serialize/util/hkbuiltintyperegistry.cpp:371
// 0xb2e210 hkDynamicClassNameRegistry::registerList
// CI hash: 0xb2e210 ?registerList@hkDynamicClassNameRegistry@@QEAAXPEBQEBD@Z
#include "Globals_b2e210.h"

void hkDynamicClassNameRegistry::registerList(const char* const* ppcNames)
{
    for (; *ppcNames; ++ppcNames)
        add(*ppcNames, 0);
}
