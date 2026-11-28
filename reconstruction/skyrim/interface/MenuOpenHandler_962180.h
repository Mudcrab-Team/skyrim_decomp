// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// MenuOpenHandler, MenuOpenHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, InputEvent, UserEvents, UIPauseState, MenuControlsState, gUserEvents, gUIPauseState, gMenuControlsState, gDisableMenus, QUserEvent, GameIsPaused, numPausesGame: GUESS(low)
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
    std::uint8_t unk00[0x60];  // 00
    BSFixedString unk60;  // 60
    std::uint8_t unk68[0x18];  // 68
    BSFixedString unk80;  // 80
    std::uint8_t unk88[0x88];  // 88
    BSFixedString unk110;  // 110
    BSFixedString unk118;  // 118
    std::uint8_t unk120[0x168];  // 120
    BSFixedString unk288;  // 288
    BSFixedString unk290;  // 290
    BSFixedString unk298;  // 298
    BSFixedString unk2A0;  // 2A0
    std::uint8_t unk2A8[0x08];  // 2A8
    BSFixedString unk2B0;  // 2B0
};
static_assert(offsetof(UserEvents, unk60) == 0x60, "unk60 offset");
static_assert(offsetof(UserEvents, unk80) == 0x80, "unk80 offset");
static_assert(offsetof(UserEvents, unk110) == 0x110, "unk110 offset");
static_assert(offsetof(UserEvents, unk118) == 0x118, "unk118 offset");
static_assert(offsetof(UserEvents, unk288) == 0x288, "unk288 offset");
static_assert(offsetof(UserEvents, unk2B0) == 0x2B0, "unk2B0 offset");

struct UIPauseState
{
    std::uint8_t unk00[0x170];  // 00
    std::uint32_t numPausesGame;  // 170

    bool GameIsPaused() const
    {
        return numPausesGame > 0;
    }
};
static_assert(offsetof(UIPauseState, numPausesGame) == 0x170, "numPausesGame offset");

struct MenuControlsState
{
    std::uint8_t unk00[0x20];  // 00
    std::uint32_t unk20;  // 20
};
static_assert(offsetof(MenuControlsState, unk20) == 0x20, "unk20 offset");

extern UserEvents* gUserEvents;
extern UIPauseState* gUIPauseState;
extern MenuControlsState* gMenuControlsState;
extern bool gDisableMenus;

class MenuOpenHandler
{
public:
    virtual ~MenuOpenHandler();
    virtual bool CanProcess(InputEvent* a_event);  // compared: 0x962180
};
