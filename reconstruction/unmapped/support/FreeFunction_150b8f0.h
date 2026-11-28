// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function150b8f0, treated as adapted: shaped like NiTArray::SetSize in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00bc0000_o2.cpp:7759
// SPDX-License-Identifier: CC0-1.0
// PtrArray_150b8f0, Alloc_150b8f0, Free_150b8f0, Function150b8f0, unk00, data, maxSize, size, count, bytes, ptr, arr, newSize: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct PtrArray_150b8f0
{
    std::uint64_t unk00;     // 0x00
    void** data;             // 0x08
    std::uint16_t maxSize;   // 0x10
    std::uint16_t size;      // 0x12
    std::uint16_t count;     // 0x14
};
static_assert(offsetof(PtrArray_150b8f0, data) == 0x08, "data offset");
static_assert(offsetof(PtrArray_150b8f0, maxSize) == 0x10, "maxSize offset");
static_assert(offsetof(PtrArray_150b8f0, size) == 0x12, "size offset");
static_assert(offsetof(PtrArray_150b8f0, count) == 0x14, "count offset");

void* Alloc_150b8f0(std::size_t bytes);
void Free_150b8f0(void* ptr);
void Function150b8f0(PtrArray_150b8f0* arr, std::uint32_t newSize);
