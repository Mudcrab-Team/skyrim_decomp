// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x12dc260
// Adapted bodies: none.
// gHeapContext12dc260, gHeapFree12dc260, BufferSlot12dc260, DualBufferHolder12dc260: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

extern void* gHeapContext12dc260;

extern void (*gHeapFree12dc260)(void*);

struct BufferSlot12dc260 {
    void* data;
    std::size_t size;
    std::size_t capacity;

    ~BufferSlot12dc260() noexcept
    {
        if (data != nullptr) {
            if (gHeapContext12dc260 != nullptr && gHeapFree12dc260 != nullptr) {
                gHeapFree12dc260(data);
            }
            data = nullptr;
            size = 0;
            capacity = 0;
        }
    }
};

struct DualBufferHolder12dc260 {
    BufferSlot12dc260 primary;
    std::uint64_t reserved18[13];
    BufferSlot12dc260 secondary;

    ~DualBufferHolder12dc260() noexcept;
};
