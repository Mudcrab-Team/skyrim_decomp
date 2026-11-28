// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// CallableBase142160: GUESS(low)
// CallableImpl142160: GUESS(low)
#pragma once

#include <cstdint>

struct CallableBase142160
{
    virtual CallableBase142160* Move(void* dst) = 0;
};

struct CallableImpl142160 : CallableBase142160
{
    CallableBase142160* Move(void* dst) override;

    std::uint64_t unk08;
    std::uint8_t flag10;
    std::uint8_t flag11;
    std::uint8_t flag12;
    std::uint64_t unk18;
};
