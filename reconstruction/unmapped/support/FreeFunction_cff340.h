// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Heapcff340, StringBuffercff340, g_globalHeapcff340, Functioncff340, Slot0, Slot1, Slot2, Slot3, Slot4, Slot5, Slot6, Slot7, Slot8, Slot9, Alloc, Realloc, data, size, capacity, growSize, lengthIsSize, heap, buffer, newSize, bytes, desc, ptr: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Heapcff340
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual char* Alloc(std::size_t bytes, const void* desc);
    virtual char* Realloc(void* ptr, std::size_t bytes);
};

extern Heapcff340* g_globalHeapcff340;

struct StringBuffercff340
{
    char* data;              // 0x00
    std::size_t size;        // 0x08
    std::size_t capacity;    // 0x10
    std::size_t growSize;    // 0x18
    bool lengthIsSize;       // 0x20
    Heapcff340* heap;        // 0x28
};
static_assert(offsetof(StringBuffercff340, lengthIsSize) == 0x20, "lengthIsSize offset");
static_assert(offsetof(StringBuffercff340, heap) == 0x28, "heap offset");

void Functioncff340(StringBuffercff340* buffer, std::size_t newSize);
