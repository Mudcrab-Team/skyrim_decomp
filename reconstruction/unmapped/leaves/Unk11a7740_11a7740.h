// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk11a7740: STANDIN GUESS(low)
// Unk11a7740::Function11a7740: GUESS(low)
// FlagObject11a7740: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct FlagObject11a7740 { std::uint8_t unknown00[340]; std::uint32_t flags; };
constexpr std::uint32_t kFlag11a7740 = 32;
class Unk11a7740
{
public:
    static void Function11a7740(FlagObject11a7740* object);
};
