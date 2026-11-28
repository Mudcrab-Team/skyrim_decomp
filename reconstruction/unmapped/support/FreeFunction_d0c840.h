// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Childd0c840, Holderd0c840, Functiond0c840, Slot0, Slot1, GetType, unk00, child, holder, expectedType: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Childd0c840
{
    virtual void Slot0();
    virtual void Slot1();
    virtual std::uint32_t GetType();
};

struct Holderd0c840
{
    std::uint64_t unk00[2];  // 0x00
    Childd0c840* child;      // 0x10
};
static_assert(offsetof(Holderd0c840, child) == 0x10, "child offset");

bool Functiond0c840(const Holderd0c840* holder, std::uint32_t expectedType);
