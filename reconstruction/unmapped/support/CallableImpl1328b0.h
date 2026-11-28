// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallableBase1328b0, CallableImpl1328b0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <new>

struct CallableBase1328b0
{
    virtual CallableBase1328b0* Copy(void* a_where) const = 0;
};

struct CallableImpl1328b0 : CallableBase1328b0
{
    CallableBase1328b0* Copy(void* a_where) const override;  // compared: 0x1328b0

    void* ptr08;          // 0x08
    std::uint8_t flag10;  // 0x10
    std::uint8_t flag11;  // 0x11
    std::uint8_t flag12;  // 0x12
    void* ptr18;          // 0x18
};
