// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// PlayerControls, sub_140706880: CRASHLOGGER_PDB(59818@2026.10.24)
// InputHandler7afcb0, HeldHandler7afcb0, unk00, unk08, unk1B, unk4C, unk4E, unk180, unk188, unk1A0, unk1A8, unk1B8, unk1C0, ClearState, VFunc: GUESS(low)
// 0x7afcb0 PlayerControls::sub_140706880
// Adapted bodies: none
#pragma once

#include <cstddef>
#include <cstdint>

class InputHandler7afcb0
{
public:
    virtual void VFunc0();
    virtual void VFunc1();
    virtual void VFunc2();
    virtual void VFunc3();
    virtual void VFunc4();
    virtual void VFunc5();
    virtual void VFunc6();
    virtual void VFunc7();
    virtual void ClearState(std::uint8_t a_value);
};

struct HeldHandler7afcb0
{
    std::uint8_t unk00[0x1B];
    bool unk1B;
};

class PlayerControls
{
public:
    void sub_140706880();

    std::uint8_t unk00[0x4C];
    std::uint16_t unk4C;
    std::uint8_t unk4E[0x132];
    InputHandler7afcb0* unk180;
    std::uint8_t unk188[0x18];
    HeldHandler7afcb0* unk1A0;
    std::uint8_t unk1A8[0x10];
    InputHandler7afcb0* unk1B8;
    InputHandler7afcb0* unk1C0;
};

static_assert(offsetof(PlayerControls, unk4C) == 0x4C, "unk4C offset");
static_assert(offsetof(PlayerControls, unk180) == 0x180, "unk180 offset");
static_assert(offsetof(PlayerControls, unk1A0) == 0x1A0, "unk1A0 offset");
static_assert(offsetof(PlayerControls, unk1B8) == 0x1B8, "unk1B8 offset");
static_assert(offsetof(PlayerControls, unk1C0) == 0x1C0, "unk1C0 offset");
static_assert(offsetof(HeldHandler7afcb0, unk1B) == 0x1B, "unk1B offset");
