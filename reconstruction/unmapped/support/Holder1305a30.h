// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Element1305a30, Holder1305a30: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <memory>

struct Element1305a30;

struct Holder1305a30
{
    std::shared_ptr<Element1305a30> GetShared() const;  // compared: 0x1305a30

    std::uint64_t unk00[3];               // 0x00
    std::shared_ptr<Element1305a30> ptr;  // 0x18
};
