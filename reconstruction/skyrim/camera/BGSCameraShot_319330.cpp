// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x319330 BGSCameraShot::IsValid
// Adapted bodies: none
#include "BGSCameraShot_319330.h"

// Checks that the camera shot action is valid and any non-empty model path has loaded data.
bool BGSCameraShot::IsValid() const
{
    if (cameraAction != 3 && (modelPath.Length() == 0 || unkA0 != nullptr)) {
        return true;
    }
    return false;
}
