// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// ReadyWeaponHandler, ReadyWeaponHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, InputEvent, UserEvents, gUserEvents, QUserEvent, readyWeapon: GUESS(low)
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
    std::uint8_t  unk00[0x68];  // 00
    BSFixedString readyWeapon;  // 68
};
static_assert(offsetof(UserEvents, readyWeapon) == 0x68, "readyWeapon offset");

extern UserEvents* gUserEvents;

class ReadyWeaponHandler
{
public:
    virtual ~ReadyWeaponHandler();
    virtual bool CanProcess(InputEvent* a_event);  // compared: 0x7b5060
};
