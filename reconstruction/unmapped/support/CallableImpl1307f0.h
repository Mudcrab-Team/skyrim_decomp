// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallableBase1307f0, CallableImpl1307f0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <new>

struct CallableBase1307f0
{
    virtual CallableBase1307f0* Copy(void* a_where) const = 0;
};

struct CallableImpl1307f0 : CallableBase1307f0
{
    CallableBase1307f0* Copy(void* a_where) const override;  // compared: 0x1307f0

    void* ptr08;          // 0x08
    std::uint8_t flag10;  // 0x10
    std::uint8_t flag11;  // 0x11
    std::uint8_t flag12;  // 0x12
    void* ptr18;          // 0x18
};
