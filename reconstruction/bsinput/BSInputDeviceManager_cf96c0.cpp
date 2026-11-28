// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSInputDeviceManager, BSInputDeviceManager::GetButtonNameFromID: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xcf96c0 BSInputDeviceManager::GetButtonNameFromID
#include "BSInputDeviceManager_cf96c0.h"

// Looks up the input device and queries its mapped button name string.
bool BSInputDeviceManager::GetButtonNameFromID(std::int32_t a_device, std::uint32_t a_id, BSFixedString& a_out) const
{
    BSIInputDevice* dev = devices[a_device];
    if (dev != nullptr && dev->GetKeyMapping(a_id, a_out))
    {
        return true;
    }
    return false;
}
