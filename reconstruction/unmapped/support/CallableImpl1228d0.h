// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallableBase1228d0, CallableImpl1228d0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <new>

struct CallableBase1228d0
{
    virtual CallableBase1228d0* Move(void* a_where) = 0;
};

struct CallableImpl1228d0 : CallableBase1228d0
{
    CallableBase1228d0* Move(void* a_where) override;  // compared: 0x1228d0

    void* ptr08;          // 0x08
    std::uint8_t flag10;  // 0x10
    std::uint8_t flag11;  // 0x11
    std::uint8_t flag12;  // 0x12
    void* ptr18;          // 0x18
};
