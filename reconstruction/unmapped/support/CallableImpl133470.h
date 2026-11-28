// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallableBase133470, CallableImpl133470: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <new>

struct CallableBase133470
{
    virtual CallableBase133470* Copy(void* a_where) const = 0;
};

struct CallableImpl133470 : CallableBase133470
{
    CallableBase133470* Copy(void* a_where) const override;  // compared: 0x133470

    void* ptr08;          // 0x08
    std::uint8_t flag10;  // 0x10
    std::uint8_t flag11;  // 0x11
    std::uint8_t flag12;  // 0x12
    void* ptr18;          // 0x18
};
