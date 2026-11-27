// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk196600: STANDIN GUESS(low)
// Unk196600::Function196600: GUESS(low)
// FlagFields196600: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct FlagFields196600 { std::uint8_t unknown00[154]; std::uint8_t flag; };


class Unk196600
{
public:
    bool Function196600(const FlagFields196600* value);
};
