// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallableBase122890, CallableImpl122890: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <new>

struct CallableBase122890
{
    virtual CallableBase122890* Copy(void* a_where) const = 0;
};

struct CallableImpl122890 : CallableBase122890
{
    CallableBase122890* Copy(void* a_where) const override;  // compared: 0x122890

    void* ptr08;          // 0x08
    std::uint8_t flag10;  // 0x10
    std::uint8_t flag11;  // 0x11
    std::uint8_t flag12;  // 0x12
    void* ptr18;          // 0x18
};
