// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// LookHandler, LookHandler::ProcessMouseMove: CRASHLOGGER_PDB(59818@2026.10.24)
// MouseMoveEvent, PlayerControlsData, mouseInputX, mouseInputY, lookX, lookY: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct MouseMoveEvent
{
    std::uint8_t unk00[0x28];  // 00
    std::int32_t mouseInputX;  // 28
    std::int32_t mouseInputY;  // 2C
};
static_assert(offsetof(MouseMoveEvent, mouseInputX) == 0x28, "mouseInputX offset");
static_assert(offsetof(MouseMoveEvent, mouseInputY) == 0x2C, "mouseInputY offset");

struct PlayerControlsData
{
    std::uint64_t unk00;  // 00
    float lookX;  // 08
    float lookY;  // 0C
};
static_assert(offsetof(PlayerControlsData, lookX) == 0x08, "lookX offset");
static_assert(offsetof(PlayerControlsData, lookY) == 0x0C, "lookY offset");

class LookHandler
{
public:
    virtual ~LookHandler();
    virtual void ProcessMouseMove(MouseMoveEvent* a_event, PlayerControlsData* a_data);  // compared: 0x7b3270
};
