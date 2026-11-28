// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallableBase130740, CallableImpl130740: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <new>

struct CallableBase130740
{
    virtual CallableBase130740* Copy(void* a_where) const = 0;
};

struct CallableImpl130740 : CallableBase130740
{
    CallableBase130740* Copy(void* a_where) const override;  // compared: 0x130740

    void* ptr08;          // 0x08
    std::uint8_t flag10;  // 0x10
    std::uint8_t flag11;  // 0x11
    std::uint8_t flag12;  // 0x12
    void* ptr18;          // 0x18
};
