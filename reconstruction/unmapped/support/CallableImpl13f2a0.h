// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// CallableBase13f2a0: GUESS(low)
// CallableImpl13f2a0: GUESS(low)
#pragma once

#include <cstdint>

struct CallableBase13f2a0
{
    virtual CallableBase13f2a0* Copy(void* dst) const = 0;
};

struct CallableImpl13f2a0 : CallableBase13f2a0
{
    CallableBase13f2a0* Copy(void* dst) const override;

    std::uint64_t unk08;
    std::uint8_t flag10;
    std::uint8_t flag11;
    std::uint8_t flag12;
    std::uint64_t unk18;
};
