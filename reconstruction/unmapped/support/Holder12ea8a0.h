// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Element12ea8a0, Holder12ea8a0: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <memory>

struct Element12ea8a0;

struct Holder12ea8a0
{
    void Reset();  // compared: 0x12ea8a0

    std::uint64_t unk00;                  // 0x00
    std::uint64_t unk08;                  // 0x08
    std::uint64_t unk10;                  // 0x10
    std::uint64_t unk18;                  // 0x18
    std::shared_ptr<Element12ea8a0> ptr;  // 0x20
};
