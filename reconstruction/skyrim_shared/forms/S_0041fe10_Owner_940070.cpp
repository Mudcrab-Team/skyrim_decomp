// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: S_0041fe10_Owner::ReleaseStorage_0041fe10.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/extradatalist.cpp:14141
// 0x940070 S_0041fe10_Owner::ReleaseStorage_0041fe10
#include "S_0041fe10_Owner_940070.h"

void S_0041fe10_Owner::ReleaseStorage_0041fe10()
{
    if (unk0c)
        delete unk0c;
    unk0c = 0;
}
