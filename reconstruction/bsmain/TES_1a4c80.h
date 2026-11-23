// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TES, TES::GetModeName: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TES
{
public:
    static const char* GetModeName(std::uint32_t mode);  // compared: 0x1a4c80
};
