// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xceab70 BSSmallBlockAllocator::BSSmallBlockAllocator
// Adapted bodies: none
#include "BSSmallBlockAllocator_ceab70.h"

BSSmallBlockAllocator::BSSmallBlockAllocator()
    : unk00(nullptr), unk08(nullptr), unk10(nullptr), unk18(nullptr)
{
    InitializeCriticalSection(&guard);
}
