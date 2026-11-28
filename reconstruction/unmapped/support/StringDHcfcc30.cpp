// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xcfcc30 StringDHcfcc30::StringDHcfcc30
// Adapted bodies: none
#include "StringDHcfcc30.h"

#include <intrin.h>

// Initializes a heap-bound string with the shared empty-string sentinel and increments its atomic refcount.
StringDHcfcc30::StringDHcfcc30(void* targetHeap) : heap(targetHeap)
{
    // Shared empty-string sentinel is referenced across threads.
    _InterlockedExchangeAdd(&g_emptyStringDatacfcc30.refCount, 1);
    dataBits = reinterpret_cast<std::uintptr_t>(&g_emptyStringDatacfcc30) | 2u;
}
