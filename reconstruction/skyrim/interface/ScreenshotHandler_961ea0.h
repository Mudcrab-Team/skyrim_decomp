// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: AutoMemContext::AutoMemContext, AutoMemContext::~AutoMemContext, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:26311
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019
// SPDX-License-Identifier: CC0-1.0
// ScreenshotHandler, ScreenshotHandler::ProcessButton, screenshotQueued, multiScreenshotQueued, ButtonEvent, value, heldDownSecs, UserEvents, screenshot, multiScreenshot, AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
// InputEvent, BSFixedString, QUserEvent, HasIDCode, GetSingleton, gUserEvents, gTlsScopeId: GUESS(low) STANDIN
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

class ButtonEvent : public InputEvent
{
public:
    std::uint8_t unk08[0x20];
    float value;
    float heldDownSecs;
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

extern __declspec(thread) std::uint32_t gTlsScopeId;

class AutoMemContext
{
public:
    explicit AutoMemContext(std::uint32_t a_id) : saved(gTlsScopeId)
    {
        gTlsScopeId = a_id;
    }

    ~AutoMemContext();

private:
    std::uint32_t saved;
};

class ScreenshotHandler
{
public:
    bool ProcessButton(ButtonEvent* a_event);

    std::uint8_t unk00[0x10];
    bool screenshotQueued;
    bool multiScreenshotQueued;
};

static_assert(offsetof(ButtonEvent, value) == 0x28, "value offset");
static_assert(offsetof(ButtonEvent, heldDownSecs) == 0x2C, "heldDownSecs offset");
static_assert(offsetof(ScreenshotHandler, screenshotQueued) == 0x10, "screenshotQueued offset");
static_assert(offsetof(ScreenshotHandler, multiScreenshotQueued) == 0x11, "multiScreenshotQueued offset");
