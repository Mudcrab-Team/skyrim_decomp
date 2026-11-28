// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// StaticArray11d760, gStaticArray11d760, Function11d760: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct StaticArray11d760
{
    void* data;          // 0x00
    std::uint64_t unk08; // 0x08
    std::uint32_t size;  // 0x10

    void Deallocate();
};

extern StaticArray11d760 gStaticArray11d760;

void Function11d760();  // compared: 0x11d760
