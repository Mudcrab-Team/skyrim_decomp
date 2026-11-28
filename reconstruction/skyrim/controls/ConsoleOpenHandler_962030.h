// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ConsoleOpenHandler, ConsoleOpenHandler::CanProcess, InputEvent, UserEvents: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, QUserEvent, consoleEvent, gUserEvents, unknown00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct BSFixedString
{
    bool operator==(const BSFixedString& a_rhs) const { return data == a_rhs.data; }

    const char* data;
};

class InputEvent
{
public:
    virtual ~InputEvent();
    virtual void Slot01();
    virtual const BSFixedString& QUserEvent() const;  // slot 02 (+0x10)
};

class UserEvents
{
public:
    std::uint8_t unknown00[0x108];
    BSFixedString consoleEvent;  // 108
};
static_assert(offsetof(UserEvents, consoleEvent) == 0x108, "consoleEvent offset");

extern UserEvents* gUserEvents;

class ConsoleOpenHandler
{
public:
    virtual ~ConsoleOpenHandler();
    virtual bool CanProcess(InputEvent* a_event);  // compared: 0x962030
};
