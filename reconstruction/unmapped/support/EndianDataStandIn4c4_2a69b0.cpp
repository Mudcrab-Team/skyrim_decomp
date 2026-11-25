// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: EndianDataStandIn4c4::Func004c45e0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:2052
// 0x2a69b0 EndianDataStandIn4c4::Func004c45e0
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:2024
// Adapted helpers: SwapEndianU
// CI hash: 0x2a69b0 ?Func004c45e0@EndianDataStandIn4c4@@QEAAXXZ
#include "EndianDataStandIn4c4_2a69b0.h"

void EndianDataStandIn4c4::Func004c45e0()
{
    SwapEndianU(unk04);
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 2; j++)
            SwapEndianU(unk08[i][j]);
    SwapEndianU(unkB4);
    SwapEndianU(unkB8);
    SwapEndianU(unkB0);
    SwapEndianU(unkEC);
    SwapEndianU(unkBC);
    SwapEndianU(unkC0);
    SwapEndianU(unkC4);
    SwapEndianU(unkE4);
    SwapEndianU(unkE8);
    SwapEndianU(unkCC);
    SwapEndianU(unkD0);
    SwapEndianU(unkD4);
    SwapEndianU(unkD8);
    SwapEndianU(unkDC);
    SwapEndianU(unkF0);
}
