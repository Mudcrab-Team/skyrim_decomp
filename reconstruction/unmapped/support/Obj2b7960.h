// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2b7960::Function2b7960, treated as adapted: shaped like BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Array2b7960, Obj2b7960, Obj2b7960::Function2b7960, g_array2b7960: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Array2b7960
{
    void* data;              // 0x00
    std::uint32_t capacity;  // 0x08
    std::uint32_t unk0C;     // 0x0C
    std::uint32_t size;      // 0x10

    void Deallocate();
};

static_assert(offsetof(Array2b7960, size) == 0x10, "size offset");

extern Array2b7960 g_array2b7960;

class Obj2b7960
{
public:
    static void Function2b7960(bool a_deallocate);
};
