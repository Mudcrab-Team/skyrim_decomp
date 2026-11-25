// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00d86100.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00d80000_o2.cpp:2414
// 0x1104050 Func00d86100
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00d80000_o2.cpp:2387
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00d80000_o2.cpp:2153
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00d80000_o2.cpp:2401
// Adapted helpers: BinaryWrite, NiStreamSaveBinaryD861
#include "Globals_1104050.h"

void Func00d86100(NiStreamD861& kStream, DataD861* pkData)
{
    NiStreamSaveBinaryD861(*kStream.m_pBackingStream, pkData->m_0c);
    NiStreamSaveBinaryD861(*kStream.m_pBackingStream, pkData->m_10);
}
