// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the listing; names from community headers.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xeefac0 NiCamera::Functioneefac0
// 0xef1770 NiCamera::UpdateWorldData
// 0xef1950 NiCamera::UpdateWorldBound
// 0xef1a10 NiCamera::~NiCamera
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "NiCamera.h"

NiCamera::NiCamera()
{
}

void NiCamera::Functioneefac0()
{
    NiCamera::~NiCamera();
}

void NiCamera::UpdateWorldData()
{
    BaseUpdateWorldData();
    UpdateCameraWorldData();
}

void NiCamera::UpdateWorldBound()
{
    worldBoundCopyA = worldBoundA;
    worldBoundCopyB = worldBoundB;
    worldBoundCopyC = worldBoundC;
}
