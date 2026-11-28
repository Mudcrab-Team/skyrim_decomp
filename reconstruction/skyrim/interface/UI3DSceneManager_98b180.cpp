// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x98b180 UI3DSceneManager::SetCameraRotate_1408d3990
#include "UI3DSceneManager_98b180.h"

// Apply a new local rotation matrix to the UI 3D scene camera and update its transforms.
void UI3DSceneManager::SetCameraRotate_1408d3990(const NiMatrix3& a_rotate)
{
    if (camera) {
        camera->localRotate = a_rotate;
        NiUpdateData updateData;
        updateData.time = 0.0f;
        updateData.flags = 0;
        camera->Update(updateData);
    }
}
