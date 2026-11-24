// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: bhkEntity::~bhkEntity.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesobjectrefr_o2_variant.cpp:490
// 0x1082fd0 bhkEntity::~bhkEntity
#include "Globals_1082fd0.h"

bhkEntity::~bhkEntity()
{
    void* p = m4;
    if (p)
    {
        void* q = *(void**)((char*)p + 0x2b0);
        if (q)
            ((hkReferencedObject*)q)->removeReference();
        *(void**)((char*)p + 0x2b0) = 0;
    }
    Func00c876a0();
    --Data012681fc;
}
