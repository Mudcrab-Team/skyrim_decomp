// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: fnv_00e05030::hkObjectResource::Routine140BE4200.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/serialize/resource/hkobjectresource.cpp:393
// 0xcc02a0 fnv_00e05030::hkObjectResource::Routine140BE4200
// Adapted helpers: hkBoolD46D
#include "Globals_cc02a0.h"

namespace fnv_00e05030 {
void* hkObjectResource::Routine140BE4200(const char* pcName, hkBool abMatch)
{
    if (pcName)
    {
        Registry* reg = unk10;
        const char* n = unk0C->getName();
        Func00d46d40_s* node1 = reg->GetClassByName(n);
        Func00d46d40_s* node2 = reg->GetClassByName(pcName);
        abMatch = node2->Func00d46d80(node1);
        if (abMatch.m_cBooleanValue)
            return unk08;
        return 0;
    }
    return unk08;
}
}
