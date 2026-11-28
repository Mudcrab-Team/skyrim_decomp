// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// QuickSaveLoadHandler, QuickSaveLoadHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, InputEvent, UserEvents, gUserEvents, QUserEvent: GUESS(low)
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
    std::uint8_t  unk00[0xC8];  // 00
    BSFixedString quicksave;    // C8
    BSFixedString quickload;    // D0
    BSFixedString quickInventory;  // D8
};
static_assert(offsetof(UserEvents, quicksave) == 0xC8, "quicksave offset");
static_assert(offsetof(UserEvents, quickload) == 0xD0, "quickload offset");
static_assert(offsetof(UserEvents, quickInventory) == 0xD8, "quickInventory offset");

extern UserEvents* gUserEvents;

class QuickSaveLoadHandler
{
public:
    virtual ~QuickSaveLoadHandler();
    virtual bool CanProcess(InputEvent* a_event);  // compared: 0x9622f0
};
