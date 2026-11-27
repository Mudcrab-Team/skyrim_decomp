// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCamera, NiPoint3, NiPlane, NiFrustumPlanes, BoundInFrustum, activePlanes, basePlaneStates: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBound, center, radius, cullingPlanes, normal, constant: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetFromCamera, g_frameCounter: GUESS(low)
#pragma once

#include <cstdint>

class NiCamera;

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiBound
{
    NiPoint3 center;
    float radius;
};
static_assert(sizeof(NiBound) == 0x10, "NiBound size");

struct NiPlane
{
    NiPlane();

    NiPoint3 normal;
    float constant;
};
static_assert(sizeof(NiPlane) == 0x10, "NiPlane size");

struct NiFrustumPlanes
{
    NiFrustumPlanes() : activePlanes(0x3F), basePlaneStates(0x3F) {}

    void SetFromCamera(const NiCamera& camera);

    NiPlane cullingPlanes[6];  // 00
    std::uint32_t activePlanes;  // 60
    std::uint32_t basePlaneStates;  // 64
};

extern std::uint32_t g_frameCounter;

class NiCamera
{
public:
    static bool BoundInFrustum(const NiBound& bound, NiCamera* camera);
};
