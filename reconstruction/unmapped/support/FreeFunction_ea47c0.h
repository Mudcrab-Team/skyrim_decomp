// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Device_ea47c0, g_devices_ea47c0, Functionea47c0, active, unk01, handle, unk08, targetHandle, requireActive: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Device_ea47c0
{
    std::uint8_t active;        // 0x0000
    std::uint8_t unk01[3];      // 0x0001
    std::uint32_t handle;       // 0x0004
    std::uint8_t unk08[0x23B0]; // 0x0008
};
static_assert(sizeof(Device_ea47c0) == 0x23B8, "Device_ea47c0 size");

extern Device_ea47c0 g_devices_ea47c0[4];

Device_ea47c0* Functionea47c0(std::uint32_t targetHandle, bool requireActive);
