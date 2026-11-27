// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk15550d0: STANDIN GUESS(low)
// Unk15550d0::Function15550d0: GUESS(low)
// Unk15550d0::value, Unk15550d0::index, Unk15550d0::context, SharedRef: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <atomic>
struct SharedRef { virtual void Unknown0(); virtual void Destroy(); std::atomic<std::uint32_t> references; };

class Unk15550d0
{
public:
    void Function15550d0();
    SharedRef* value;
    std::uint64_t index;
    void* context;
};
static_assert(offsetof(Unk15550d0, value) == 0, "field offset");
static_assert(offsetof(Unk15550d0, index) == 8, "field offset");
static_assert(offsetof(Unk15550d0, context) == 16, "field offset");
