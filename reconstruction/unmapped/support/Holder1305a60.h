// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Holder1305a60, Function1305a60, unk00, shared: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

class Holder1305a60
{
public:
    std::uint64_t unk00[3];        // 0x00
    std::shared_ptr<void> shared;  // 0x18

    std::shared_ptr<void> Function1305a60() const;
};
static_assert(offsetof(Holder1305a60, shared) == 0x18, "shared offset");
