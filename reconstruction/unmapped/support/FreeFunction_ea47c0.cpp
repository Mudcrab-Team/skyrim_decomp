// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xea47c0 Functionea47c0
// Adapted bodies: none
#include "FreeFunction_ea47c0.h"

// Searches the four device slots for targetHandle, optionally requiring the slot to be active.
// The community name table calls this getDeviceByHandle (a hint, not proof); the names in this unit are stand-ins.
Device_ea47c0* Functionea47c0(std::uint32_t targetHandle, bool requireActive)
{
    for (int i = 0; i < 4; ++i) {
        Device_ea47c0* device = &g_devices_ea47c0[i];
        if ((!requireActive || device->active != 0) && device->handle == targetHandle) {
            return device;
        }
    }
    return nullptr;
}
