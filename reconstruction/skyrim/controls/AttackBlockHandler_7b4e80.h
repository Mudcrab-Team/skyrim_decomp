// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// AttackBlockHandler, AttackBlockHandler::CanProcess, UserEvents, leftAttack, rightAttack: CRASHLOGGER_PDB(59818@2026.10.24)
// InputEvent, BSFixedString, HasIDCode, QUserEvent, GetSingleton, gUserEvents: GUESS(low) STANDIN
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
    static UserEvents* GetSingleton();

    std::uint8_t unk00[0x40];
    BSFixedString leftAttack;
    BSFixedString rightAttack;
};

extern UserEvents* gUserEvents;
inline UserEvents* UserEvents::GetSingleton() { return gUserEvents; }

class AttackBlockHandler
{
public:
    bool CanProcess(InputEvent* a_event);
};

static_assert(offsetof(UserEvents, leftAttack) == 0x40, "leftAttack offset");
static_assert(offsetof(UserEvents, rightAttack) == 0x48, "rightAttack offset");
