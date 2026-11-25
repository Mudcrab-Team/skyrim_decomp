// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00a2cc60.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a20000_o2.cpp:3610
// 0xf90960 Func00a2cc60
#include "BSStream_f90960.h"

void Func00a2cc60(A2CC60Stream* pkStream, A2CC60Entry* pkEntries, unsigned int ItemUpdateArray) {
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        WriteEnabledFlag(pkStream, &pkEntries[i]);
}
