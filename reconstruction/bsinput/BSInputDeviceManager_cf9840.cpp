// CI hash: 0xcf9840 ?Functioncf9840@BSInputDeviceManager@@QEAA_NXZ
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSInputDeviceManager: STANDIN GUESS(low)
// BSInputDeviceManager::Functioncf9840: GUESS(low)
// BSInputDeviceManager::device, InputDeviceViewcf9840: GUESS(low)
// 0xcf9840 BSInputDeviceManager::Functioncf9840
#include "BSInputDeviceManager_cf9840.h"

// Report the optional device query result.
bool BSInputDeviceManager::Functioncf9840()
{
    return device && device->Query() != 0;
}
