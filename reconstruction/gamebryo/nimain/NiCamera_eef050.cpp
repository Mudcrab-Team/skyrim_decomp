// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// NiCamera, NiAVObject, CopyMembers, worldToCam, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust, NiFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// worldTranslate, ViewPort: GUESS(low)
// 0xeef050 NiCamera::CopyMembers
// CI hash: 0xeef050 ?CopyMembers@NiCamera@@QEAAXPEAV1@AEAVNiCloningProcess@@@Z
#include "NiCamera_eef050.h"

#include <cstring>

void NiCamera::CopyMembers(NiCamera* destination, NiCloningProcess& cloning)
{
    NiAVObject::CopyMembers(destination, cloning);
    std::memcpy(destination->worldToCam, worldToCam, sizeof(worldToCam));
    destination->worldTranslate.x = worldTranslate.x;
    destination->worldTranslate.y = worldTranslate.y;
    destination->worldTranslate.z = worldTranslate.z;
    destination->viewFrustum = viewFrustum;
    destination->port = port;
    destination->lodAdjust = lodAdjust;
    destination->minNearPlaneDist = minNearPlaneDist;
    destination->maxFarNearRatio = maxFarNearRatio;
}
