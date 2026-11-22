// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xce8780 MemoryHeap::BlockIsInHeap
// Adapted bodies: none
#include "MemoryHeap_ce8780.h"

bool MemoryHeap::BlockIsInHeap(const void* a_block) const
{
    if (unk0A()) {
        const std::uint64_t header = *reinterpret_cast<const std::uint64_t*>(static_cast<const unsigned char*>(a_block) - 0x20);
        if (!TestBit64(header, 62)) {
            return true;
        }
    }
    return false;
}
