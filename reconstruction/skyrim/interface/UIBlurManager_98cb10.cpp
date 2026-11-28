// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0x98cb10 ??_GUIBlurManager@@UEAAPEAXI@Z
// Adapted bodies: none
// 0x98cb10 UIBlurManager::dtor_deleting
#include "UIBlurManager_98cb10.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
UIBlurManager::UIBlurManager() {}

// Clean up blur state before the singleton base clears its global instance pointer.
UIBlurManager::~UIBlurManager()
{
    Cleanup();
}
