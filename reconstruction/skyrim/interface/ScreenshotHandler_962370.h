// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScreenshotHandler, ScreenshotHandler::CanProcess, UserEvents, screenshot, multiScreenshot: CRASHLOGGER_PDB(59818@2026.10.24)
// InputEvent, BSFixedString, QUserEvent, HasIDCode, GetSingleton, gUserEvents: GUESS(low) STANDIN
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

    std::uint8_t unk00[0xF8];
    BSFixedString screenshot;
    BSFixedString multiScreenshot;
};

extern UserEvents* gUserEvents;
inline UserEvents* UserEvents::GetSingleton() { return gUserEvents; }

class ScreenshotHandler
{
public:
    bool CanProcess(InputEvent* a_event);
};

static_assert(offsetof(UserEvents, screenshot) == 0xF8, "screenshot offset");
static_assert(offsetof(UserEvents, multiScreenshot) == 0x100, "multiScreenshot offset");
