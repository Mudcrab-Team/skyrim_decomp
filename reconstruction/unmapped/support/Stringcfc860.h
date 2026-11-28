// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Heap_cfc860, StringData_cfc860, Stringcfc860, g_heap_cfc860, g_emptyStringData_cfc860, Slot0, Slot1, Slot2, Slot3, Slot4, Slot5, Slot6, Slot7, Slot8, Slot9, Alloc, size, refCount, text, data, bytes, desc, str: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Heap_cfc860
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
    virtual void* Alloc(std::size_t bytes, const void* desc);
};

extern Heap_cfc860* g_heap_cfc860;

struct StringData_cfc860
{
    std::size_t size;  // 0x00
    long refCount;     // 0x08
    char text[1];      // 0x0C
};
static_assert(offsetof(StringData_cfc860, refCount) == 0x08, "refCount offset");
static_assert(offsetof(StringData_cfc860, text) == 0x0C, "text offset");

extern StringData_cfc860 g_emptyStringData_cfc860;

class Stringcfc860
{
public:
    StringData_cfc860* data;  // 0x00

    explicit Stringcfc860(const char* str);
};
