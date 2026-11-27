// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiControllerManager::Routine14029FB70.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00440000_o2.cpp:3620
// 0x2f9ea0 NiControllerManager::Routine14029FB70
#include "NiControllerManager_2f9ea0.h"

void NiControllerManager::Routine14029FB70(float time)
{
    for (unsigned int i = 0; i < count; i++)
        items[i]->Update(time, false);
}
