// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// StringDatacfcc30, StringDHcfcc30, g_emptyStringDatacfcc30, size, refCount, dataBits, heap, targetHeap: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct StringDatacfcc30
{
    std::size_t size;  // 0x00
    long refCount;     // 0x08
};
static_assert(offsetof(StringDatacfcc30, refCount) == 0x08, "refCount offset");

extern StringDatacfcc30 g_emptyStringDatacfcc30;

class StringDHcfcc30
{
public:
    explicit StringDHcfcc30(void* targetHeap);

    std::uintptr_t dataBits;  // 0x00
    void* heap;               // 0x08
};
static_assert(sizeof(StringDHcfcc30) == 0x10, "StringDHcfcc30 size");
