// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSInputDeviceManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioncf9700: GUESS(low); provisional member name
// 0xcf9700 BSInputDeviceManager::Functioncf9700
// CI hash: 0xcf9700 ?Functioncf9700@BSInputDeviceManager@@QEAA_NHIPEAX@Z
#include "BSInputDeviceManager_cf9700.h"

// Guess: Query the selected input device when it exists.
bool BSInputDeviceManager::Functioncf9700(int device, unsigned code, void* output)
{
    auto* input = devices[device];
    if (input && input->Query(code, output)) { return true; }
    return false;
}
