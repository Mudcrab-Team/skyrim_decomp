// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallableBase133430, CallableImpl133430: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <new>

struct CallableBase133430
{
    virtual CallableBase133430* Copy(void* a_where) const = 0;
};

struct CallableImpl133430 : CallableBase133430
{
    CallableBase133430* Copy(void* a_where) const override;  // compared: 0x133430

    void* ptr08;          // 0x08
    std::uint8_t flag10;  // 0x10
    std::uint8_t flag11;  // 0x11
    std::uint8_t flag12;  // 0x12
    void* ptr18;          // 0x18
};
