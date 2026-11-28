// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// MapLookHandler, MapLookHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
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
    std::uint8_t unk00[0x30];  // 00
    BSFixedString unk30;  // 30
    std::uint8_t unk38[0x100];  // 38
    BSFixedString unk138;  // 138
    BSFixedString unk140;  // 140
    BSFixedString unk148;  // 148
    BSFixedString unk150;  // 150
    std::uint8_t unk158[0x28];  // 158
    BSFixedString unk180;  // 180
    std::uint8_t unk188[0x138];  // 188
    BSFixedString unk2C0;  // 2C0
};
static_assert(offsetof(UserEvents, unk30) == 0x30, "unk30 offset");
static_assert(offsetof(UserEvents, unk138) == 0x138, "unk138 offset");
static_assert(offsetof(UserEvents, unk180) == 0x180, "unk180 offset");
static_assert(offsetof(UserEvents, unk2C0) == 0x2C0, "unk2C0 offset");

extern UserEvents* gUserEvents;

class MapLookHandler
{
public:
    virtual ~MapLookHandler();
    virtual bool CanProcess(InputEvent* a_event);  // compared: 0x998af0

    std::uint64_t unk08[2];  // 08
    bool unk18;  // 18
};
static_assert(offsetof(MapLookHandler, unk18) == 0x18, "unk18 offset");
