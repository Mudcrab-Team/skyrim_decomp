// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// JumpHandler, JumpHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, InputEvent, UserEvents, gUserEvents, QUserEvent, jump: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct BSFixedString
{
    const char* data;  // 00

    bool operator==(const BSFixedString& a_rhs) const
    {
        return data == a_rhs.data;
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
    std::uint8_t unk00[0x78];  // 00
    BSFixedString jump;  // 78
};
static_assert(offsetof(UserEvents, jump) == 0x78, "jump offset");

extern UserEvents* gUserEvents;

class JumpHandler
{
public:
    virtual ~JumpHandler();
    virtual bool CanProcess(InputEvent* a_event);  // compared: 0x7b4f10
};
