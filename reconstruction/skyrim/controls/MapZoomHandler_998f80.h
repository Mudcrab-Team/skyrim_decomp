// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// MapZoomHandler, MapZoomHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, InputEvent, UserEvents, gUserEvents, QUserEvent: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct BSFixedString
{
    const char* data;  // 00

    bool operator==(const BSFixedString& a_rhs) const
    {
        return a_rhs.data == data;
    }
};
static_assert(sizeof(BSFixedString) == 0x08, "BSFixedString size");

class InputEvent
{
public:
    virtual ~InputEvent();  // 00
    virtual bool HasIDCode() const;  // 01
    virtual const BSFixedString& QUserEvent() const;  // 02 (0x10)
};

struct UserEvents
{
    std::uint8_t unk00[0x1E8];  // 00
    BSFixedString unk1E8;  // 1E8
    BSFixedString unk1F0;  // 1F0
};
static_assert(offsetof(UserEvents, unk1E8) == 0x1E8, "unk1E8 offset");
static_assert(offsetof(UserEvents, unk1F0) == 0x1F0, "unk1F0 offset");

extern UserEvents* gUserEvents;

class MapZoomHandler
{
public:
    virtual ~MapZoomHandler();
    virtual bool CanProcess(InputEvent* a_event);  // compared: 0x998f80
};
