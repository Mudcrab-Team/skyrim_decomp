// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Payload129e60, CallbackNode129e60, Function129e60: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>

struct Payload129e60
{
    std::uint64_t unk00;  // 0x00
};

struct CallbackNode129e60
{
    std::uint32_t id;                                                            // 0x00
    std::function<void(std::uint32_t, const Payload129e60&, std::uint32_t)> cb;  // 0x08
    std::uint32_t priority;                                                      // 0x48
    void* userData;                                                              // 0x50
    CallbackNode129e60* next;                                                    // 0x58
};

void Function129e60(CallbackNode129e60* a_node, std::uint32_t a_id, const Payload129e60& a_payload, std::uint32_t a_param);  // compared: 0x129e60
