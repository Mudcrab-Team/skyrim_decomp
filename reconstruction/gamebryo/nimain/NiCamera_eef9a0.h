// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCamera, NiAVObject, NiTransform, NiMatrix3, NiPoint3, NiBound, NiFrustum, NiUpdateData, world, worldBound, worldToCam, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust, rotate, translate, scale, fLeft, fRight, fTop, fBottom, fNear, fFar, bOrtho, left, right, top, bottom, time, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRect, center, radius, Update: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// WorldToCamMatrix: GUESS(low)
#pragma once

#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiMatrix3
{
    float entry[3][3];
};

struct NiTransform
{
    NiMatrix3 rotate;
    NiPoint3 translate;
    float scale;
};
static_assert(sizeof(NiTransform) == 0x34, "NiTransform size");

struct NiBound
{
    NiPoint3 center;
    float radius;
};
static_assert(sizeof(NiBound) == 0x10, "NiBound size");

struct NiUpdateData
{
    float time;
    std::uint32_t flags;
};
static_assert(sizeof(NiUpdateData) == 0x8, "NiUpdateData size");

struct NiFrustum
{
    explicit NiFrustum(bool ortho = false);

    float fLeft;
    float fRight;
    float fTop;
    float fBottom;
    float fNear;
    float fFar;
    bool bOrtho;
    std::uint8_t unk19[3];
};
static_assert(sizeof(NiFrustum) == 0x1C, "NiFrustum size");

template <class T>
struct NiRect
{
    NiRect(T a_left = T(0), T a_right = T(0), T a_top = T(0), T a_bottom = T(0)) :
        left(a_left), right(a_right), top(a_top), bottom(a_bottom)
    {
    }

    T left;
    T right;
    T top;
    T bottom;
};
static_assert(sizeof(NiRect<float>) == 0x10, "NiRect size");

class NiAVObject
{
public:
    NiAVObject();
    virtual ~NiAVObject();

    void Update(NiUpdateData& data);

    std::uint8_t unk08[0x74];  // 08
    NiTransform world;  // 7C
    NiTransform previousWorld;  // B0
    NiBound worldBound;  // E4
    std::uint8_t unkF4[0x1C];  // F4
};
static_assert(sizeof(NiAVObject) == 0x110, "NiAVObject size");

class NiCamera : public NiAVObject
{
public:
    NiCamera();
    ~NiCamera() override;

    void WorldToCamMatrix();

    float worldToCam[4][4];  // 110
    NiFrustum viewFrustum;  // 150
    float minNearPlaneDist;  // 16C
    float maxFarNearRatio;  // 170
    NiRect<float> port;  // 174
    float lodAdjust;  // 184
};
static_assert(sizeof(NiCamera) == 0x188, "NiCamera size");
