// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallbackNode129e00: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>

struct CallbackNode129e00
{
    ~CallbackNode129e00();  // compared: 0x129e00

    std::uint32_t id;                // 0x00
    std::function<void()> callback;  // 0x08
    std::uint32_t priority;          // 0x48
    void* userData;                  // 0x50
    CallbackNode129e00* next;        // 0x58
};

static_assert(sizeof(CallbackNode129e00) == 0x60, "CallbackNode129e00 size");
