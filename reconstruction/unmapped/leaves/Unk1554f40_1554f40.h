// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk1554f40: STANDIN GUESS(low)
// Unk1554f40::Function1554f40: GUESS(low)
// Unk1554f40::value, Unk1554f40::tag, Unk1554f40::index, SharedRef: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <atomic>
struct SharedRef { virtual void Unknown0(); virtual void Destroy(); std::atomic<std::uint32_t> references; };

class Unk1554f40
{
public:
    void Function1554f40(std::uint32_t newTag);
    SharedRef* value;
    std::uint32_t tag;
    std::uint32_t index;
};
static_assert(offsetof(Unk1554f40, value) == 0, "field offset");
static_assert(offsetof(Unk1554f40, tag) == 8, "field offset");
static_assert(offsetof(Unk1554f40, index) == 12, "field offset");
