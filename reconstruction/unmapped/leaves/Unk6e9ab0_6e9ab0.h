// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk6e9ab0: STANDIN GUESS(low)
// Unk6e9ab0::Function6e9ab0: GUESS(low)
// Unk6e9ab0::value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


void* Related6e9ab0(void* object);
std::uint32_t Fetch6e9ab0(void* object);
class Unk6e9ab0
{
public:
    std::uint32_t Function6e9ab0();
    std::uint8_t unknown0[52];
    std::uint32_t value;
};
static_assert(offsetof(Unk6e9ab0, value) == 52, "field offset");
