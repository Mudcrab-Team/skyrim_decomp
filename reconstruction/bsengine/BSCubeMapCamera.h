// Code origin: hand-written class layout and declarations adapted from the powerof3/CommonLibSSE headers named below (GPL-3.0); the compared body is written from the local listing.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSCubeMapCamera, BSCubeMapCamera::RenderCubemap, BSCubeMapCamera::~BSCubeMapCamera, BSCubeMapCamera::GetRTTI: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiRTTI: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiCamera, NiFrustum, NiRect, NiCamera::worldToCam, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// FaceEnableFlags, BSTArray, NiColorA, BSShaderAccumulator, NiAVObject, BSCubeMapCamera::scenes, accumulator, secondAccumulator, unk1B0, silhouetteColor: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiAVObject.h"

class NiRTTI;

struct NiFrustum
{
    float fLeft;  // 00
    float fRight;  // 04
    float fTop;  // 08
    float fBottom;  // 0C
    float fNear;  // 10
    float fFar;  // 14
    bool bOrtho;  // 18
};
static_assert(sizeof(NiFrustum) == 0x1C, "NiFrustum size");

struct NiRectFloat
{
    float left;  // 00
    float right;  // 04
    float top;  // 08
    float bottom;  // 0C
};

class NiCamera : public NiAVObject
{
public:
    ~NiCamera() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02

    float worldToCam[4][4];  // 110
    NiFrustum viewFrustum;  // 150
    float minNearPlaneDist;  // 16C
    float maxFarNearRatio;  // 170
    NiRectFloat port;  // 174
    float lodAdjust;  // 184
};
static_assert(sizeof(NiCamera) == 0x188, "NiCamera size");

class BSShaderAccumulator;
class NiAVObject;

enum class FaceEnableFlags : std::uint32_t
{
    kEnablePosX = 1 << 0,
    kEnableNegX = 1 << 1,
    kEnablePosY = 1 << 2,
    kEnableNegY = 1 << 3,
    kEnablePosZ = 1 << 4,
    kEnableNegZ = 1 << 5,
    kEnableAll = 0x3F
};

struct BSTArrayOfNiAVObject
{
    NiAVObject** data;  // 00
    std::uint32_t capacity;  // 08
    std::uint32_t pad0C;  // 0C
    std::uint32_t size;  // 10
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(BSTArrayOfNiAVObject) == 0x18, "BSTArray size");

struct NiColorA
{
    float r;  // 00
    float g;  // 04
    float b;  // 08
    float a;  // 0C
};

class BSCubeMapCamera : public NiCamera
{
public:
    ~BSCubeMapCamera() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    virtual void RenderCubemap(FaceEnableFlags a_faceMask, bool a_arg2, bool a_clearScenes, bool a_arg4);  // compared: 0x1559a60  // slot 35

    BSTArrayOfNiAVObject scenes;  // 188
    BSShaderAccumulator* accumulator;  // 1A0
    BSShaderAccumulator* secondAccumulator;  // 1A8
    NiCamera* unk1B0;  // 1B0
    NiColorA silhouetteColor;  // 1B8
};
static_assert(sizeof(BSCubeMapCamera) == 0x1C8, "BSCubeMapCamera size");
static_assert(offsetof(BSCubeMapCamera, silhouetteColor) == 0x1B8, "BSCubeMapCamera members");
