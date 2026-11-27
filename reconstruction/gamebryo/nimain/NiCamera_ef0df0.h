// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCamera, NiAVObject, NiObjectNET, NiObject, NiRefObject, NiNode, NiTransform, NiMatrix3, NiBound, NiPoint3, NiFrustum, WorldPtToScrPt, worldToCam, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust, left, right, top, bottom, parent, parentIndex, collisionObject, local, world, previousWorld, worldBound, flags, userData, fadeAmount, lastUpdatedFrameCounter, lodMode, flags02, unk10A, name, controllers, extra, extraDataSize, rotate, translate, scale, center, radius: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRect, unk03C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount, unk0C, unk19: GUESS(low)
// Recipe: reconstruction/recipes/o2-fpfast.json
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

struct NiBound
{
    NiPoint3 center;
    float radius;
};

struct NiFrustum
{
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
    T left;
    T right;
    T top;
    T bottom;
};
static_assert(sizeof(NiRect<float>) == 0x10, "NiRect size");

class NiNode;

class NiRefObject
{
public:
    virtual ~NiRefObject();
    std::uint32_t refCount;
    std::uint32_t unk0C;
};

class NiObject : public NiRefObject
{
};

class NiObjectNET : public NiObject
{
public:
    const char* name;
    void* controllers;
    void** extra;
    std::uint16_t extraDataSize;
};
static_assert(sizeof(NiObjectNET) == 0x30, "NiObjectNET size");

class NiAVObject : public NiObjectNET
{
public:
    NiNode* parent;
    std::uint32_t parentIndex;
    std::uint32_t unk03C;
    void* collisionObject;
    NiTransform local;
    NiTransform world;
    NiTransform previousWorld;
    NiBound worldBound;
    std::uint32_t flags;
    void* userData;
    float fadeAmount;
    std::uint32_t lastUpdatedFrameCounter;
    std::uint8_t lodMode;
    std::uint8_t flags02;
    std::uint16_t unk10A;
};
static_assert(sizeof(NiAVObject) == 0x110, "NiAVObject size");

class NiCamera : public NiAVObject
{
public:
    bool WorldPtToScrPt(const NiPoint3& in, float& xOut, float& yOut, float zeroTolerance) const;

    float worldToCam[4][4];  // 110
    NiFrustum viewFrustum;  // 150
    float minNearPlaneDist;  // 16C
    float maxFarNearRatio;  // 170
    NiRect<float> port;  // 174
    float lodAdjust;  // 184
};
static_assert(sizeof(NiCamera) == 0x188, "NiCamera size");
