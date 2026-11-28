// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ClickHandler, ClickHandler::CanProcess, InputEvent, UserEvents: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, QUserEvent, clickEvent, gUserEvents, unknown00: GUESS(low)
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
    std::uint8_t unknown00[0x2B8];
    BSFixedString clickEvent;  // 2B8
};
static_assert(offsetof(UserEvents, clickEvent) == 0x2B8, "clickEvent offset");

extern UserEvents* gUserEvents;

class ClickHandler
{
public:
    virtual ~ClickHandler();
    virtual bool CanProcess(InputEvent* a_event);  // compared: 0x962000
};
