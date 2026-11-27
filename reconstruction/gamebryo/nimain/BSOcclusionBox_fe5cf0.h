// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: NiPoint3::operator= (sibling similarity noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380 (NiPoint3::operator=, component-wise copy).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSOcclusionBox, BSOcclusionShape, BSMultiBoundShape, NiPoint3, NiMatrix3, NiFrustumPlanes, NiPlane, translation, rotation, visibilityState, updateFacesOrVertices, size, frustumPlanes, corners, unused194, boundShape, unused1A0, unused1A8, facePlaneSlots, silhouetteIndices, silhouetteCount: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiRefObject: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// normal, constant, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kZeroPoint, kIdentityMatrix, refCount, unk0C: GUESS(low)
#pragma once

#include <cstdint>

struct BSMultiBoundShape;

struct NiPoint3
{
    NiPoint3() : x(0.0f), y(0.0f), z(0.0f) {}
    NiPoint3(float a_x, float a_y, float a_z) : x(a_x), y(a_y), z(a_z) {}
    float x;
    float y;
    float z;

    NiPoint3& operator=(const NiPoint3& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }

    static const NiPoint3 kZeroPoint;
};

struct NiMatrix3
{
    float entry[3][3];

    static const NiMatrix3 kIdentityMatrix;
};

struct NiPlane
{
    NiPlane();
    NiPoint3 normal;
    float constant;
};

struct NiFrustumPlanes
{
    NiFrustumPlanes() : activePlanes(0x3F), basePlaneStates(0x3F) {}

    NiPlane cullingPlanes[6];
    std::uint32_t activePlanes;
    std::uint32_t basePlaneStates;
    std::uint32_t unk68;
    std::uint32_t unk6C;
};

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

class BSOcclusionShape : public NiObject
{
public:
    BSOcclusionShape();
    ~BSOcclusionShape() override;

    NiPoint3 translation;
    NiMatrix3 rotation;
    std::uint32_t visibilityState;
    bool updateFacesOrVertices;
};

class BSOcclusionBox : public BSOcclusionShape
{
public:
    BSOcclusionBox();
    ~BSOcclusionBox() override;

    NiPoint3 size;
    NiFrustumPlanes frustumPlanes[2];
    NiPoint3 corners[8];
    float unused194;
    BSMultiBoundShape* boundShape;
    std::uint64_t unused1A0;
    std::uint32_t unused1A8;
    std::int32_t facePlaneSlots[6];
    std::uint32_t silhouetteIndices[8];
    std::uint32_t silhouetteCount;
};
static_assert(sizeof(BSOcclusionBox) == 0x1E8, "BSOcclusionBox size");
