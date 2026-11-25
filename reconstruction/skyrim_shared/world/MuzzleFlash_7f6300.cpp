// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: body adapted from the sibling function below; the scene node access checked against the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/MuzzleFlash.cpp:186
// 0x7f6300 MuzzleFlash::DetachLight
#include "MuzzleFlash_7f6300.h"

// Take the muzzle light out of the scene before dropping the effect's reference to it.
void MuzzleFlash::DetachLight()
{
    if (spLight.m_pObject) {
        pShadowSceneNode->RemoveLight(spLight.m_pObject);
        spLight = nullptr;
    }
}
