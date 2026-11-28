// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallbackHolder12b0f0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>

struct CallbackHolder12b0f0
{
    CallbackHolder12b0f0();  // compared: 0x12b0f0
    virtual ~CallbackHolder12b0f0() = default;

    std::uint32_t refCount;          // 0x08
    std::uint32_t state;             // 0x0c
    std::uint32_t flags;             // 0x10
    std::function<void()> callback;  // 0x18
};
