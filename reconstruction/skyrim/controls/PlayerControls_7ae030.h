// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// PlayerControls, IsCamSwitchControlsEnabled: CRASHLOGGER_PDB(59818@2026.10.24)
// ControlMap7ae030, g_controlMap7ae030, unk00, unk4C, unk120: GUESS(low)
// 0x7ae030 PlayerControls::IsCamSwitchControlsEnabled
// Adapted bodies: none
#pragma once

#include <cstddef>
#include <cstdint>

struct ControlMap7ae030
{
    std::uint8_t unk00[0x120];
    std::uint32_t unk120;
};

class PlayerControls
{
public:
    bool IsCamSwitchControlsEnabled() const;

    std::uint8_t unk00[0x4C];
    bool unk4C[2];
};

extern ControlMap7ae030* g_controlMap7ae030;

static_assert(offsetof(PlayerControls, unk4C) == 0x4C, "unk4C offset");
static_assert(offsetof(ControlMap7ae030, unk120) == 0x120, "unk120 offset");
