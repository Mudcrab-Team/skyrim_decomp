// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0x8fd920 ThirdPersonState::sub_14084F780
#include "ThirdPersonState_8fd920.h"

// Resets third-person camera position and zoom offsets from saved defaults.
void ThirdPersonState::sub_14084F780(bool a_keepCurrentZoom, bool a_resetSavedZoom)
{
    posX = savedPosX;
    posY = savedPosY;
    posZ = savedPosZ;
    if (a_resetSavedZoom)
    {
        savedZoomOffset = gDefaultZoomOffset;
    }
    currentZoomOffset = savedZoomOffset;
    targetZoomOffset = gDefaultZoomOffset;
    if (!a_keepCurrentZoom)
    {
        currentZoomOffset = targetZoomOffset;
    }
}
