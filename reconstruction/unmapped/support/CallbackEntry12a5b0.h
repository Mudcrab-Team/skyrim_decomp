// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// CallbackEntry12a5b0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>

struct CallbackEntry12a5b0
{
    CallbackEntry12a5b0();  // compared: 0x12a5b0

    std::uint32_t id;                // 0x00
    std::function<void()> callback;  // 0x08
};
