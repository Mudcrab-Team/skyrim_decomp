// Source exposure: binary-analysis.
// Code origin: original value-storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk632cb0: STANDIN GUESS(low)
// Unk632cb0::Unk632cb0: GUESS(low)
// Unk632cb0::unk00, Unk632cb0::unk04: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk632cb0
{
public:
    Unk632cb0(const Unk632cb0& other);
    std::uint32_t unk00;
    std::uint32_t unk04;
};
static_assert(offsetof(Unk632cb0, unk00) == 0, "field offset");
static_assert(offsetof(Unk632cb0, unk04) == 4, "field offset");
