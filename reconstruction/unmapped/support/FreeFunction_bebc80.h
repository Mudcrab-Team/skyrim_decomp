// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Allocatorbebc80, ArrayBasebebc80, Arraybebc80, SubObjbebc80, Recordbebc80, Functionbebc80, Deallocate, data, capacity, unk0C, size, base, unk00, refCount, unk04, array, subObj, record: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Allocatorbebc80
{
    ~Allocatorbebc80();
    void Deallocate();

    void* data;              // 0x00
    std::uint32_t capacity;  // 0x08
    std::uint32_t unk0C;     // 0x0C
};
static_assert(sizeof(Allocatorbebc80) == 0x10, "Allocatorbebc80 size");

struct ArrayBasebebc80
{
    ~ArrayBasebebc80();

    std::uint32_t size;  // 0x00
};
static_assert(sizeof(ArrayBasebebc80) == 0x4, "ArrayBasebebc80 size");

struct Arraybebc80 : Allocatorbebc80
{
    ~Arraybebc80()
    {
        if (data != nullptr) {
            Deallocate();
            base.size = 0;
        }
    }

    ArrayBasebebc80 base;  // 0x10
};
static_assert(sizeof(Arraybebc80) == 0x18, "Arraybebc80 size");

struct SubObjbebc80
{
    ~SubObjbebc80();

    std::uint8_t unk00[0x48];  // 0x00
};
static_assert(sizeof(SubObjbebc80) == 0x48, "SubObjbebc80 size");

struct Recordbebc80
{
    long refCount;        // 0x00
    std::uint32_t unk04;  // 0x04
    Arraybebc80 array;    // 0x08
    SubObjbebc80 subObj;  // 0x20
};
static_assert(sizeof(Recordbebc80) == 0x68, "Recordbebc80 size");

void Functionbebc80(Recordbebc80* record);
