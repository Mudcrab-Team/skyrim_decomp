// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: ReleaseAllEntries.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp:32
// 0xc9a310 ReleaseAllEntries
#include "Globals_c9a310.h"

void ReleaseAllEntries(S_00dad640_Set* set, S_00dad640_Target* target, void* arg)
{
    for (unsigned int i = 0; i < set->count; i++)
    {
        unsigned short id = set->entries[i].id;
        if (id != 0xffff)
            target->Release(id, arg);
    }
    set->count = 0;
    set->unk0 = 0;
    set->unk1 = 0;
}
