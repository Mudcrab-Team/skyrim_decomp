// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xef1770 NiCamera::UpdateWorldData
// 0xef1950 NiCamera::UpdateWorldBound
// 0xef1a10 NiCamera::~NiCamera
#include "NiCamera.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
NiCamera::NiCamera()
{
}

// UpdateWorldData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
void NiCamera::UpdateWorldData()
{
    BaseUpdateWorldData();
    UpdateCameraWorldData();
}

// UpdateWorldBound: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
void NiCamera::UpdateWorldBound()
{
    worldBoundCopyA = worldBoundA;
    worldBoundCopyB = worldBoundB;
    worldBoundCopyC = worldBoundC;
}
