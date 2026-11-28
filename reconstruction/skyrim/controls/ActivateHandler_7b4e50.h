// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ActivateHandler, ActivateHandler::CanProcess, UserEvents, activate: CRASHLOGGER_PDB(59818@2026.10.24)
// InputEvent, BSFixedString, HasIDCode, QUserEvent, gUserEvents: GUESS(low) STANDIN
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
    virtual bool HasIDCode() const;
    virtual const BSFixedString& QUserEvent() const;
};

struct UserEvents
{
    std::uint8_t unk00[0x38];
    BSFixedString activate;
};

extern UserEvents* gUserEvents;

class ActivateHandler
{
public:
    bool CanProcess(InputEvent* a_event);
};

static_assert(offsetof(UserEvents, activate) == 0x38, "activate offset");
