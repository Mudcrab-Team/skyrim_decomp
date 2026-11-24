// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: CallSpawnTarget.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a20000_o2.cpp:1180
// 0xf8f8c0 CallSpawnTarget
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a20000_o2.cpp:1377
#include "Globals_f8f8c0.h"

void CallSpawnTarget(float afValue, char* pBufferX, char* pBufferY, SpawnTarget* pTarget)
{
    pTarget->Callee(afValue, pBufferX + 4, pBufferX + 0x14, pBufferY + 0x14, pBufferY + 4);
}
