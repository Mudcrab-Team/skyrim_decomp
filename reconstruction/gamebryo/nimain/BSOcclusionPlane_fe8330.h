// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSOcclusionPlane, BSOcclusionShape, CreateClone, CopyTransformTo, NiCloningProcess, NiPoint3, NiPoint2, NiMatrix3, NiFrustumPlanes, NiPlane, translation, rotation, visibilityState, updateFacesOrVertices, size, frustumPlanes, corners, edgeFlags, twoSided, unkF8: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiRefObject: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// normal, constant, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kZeroPoint, kIdentityMatrix, refCount, unk0C: GUESS(low)
#pragma once

#include "PortalHeapObject.h"
#include <cstdint>

class NiCloningProcess;

struct NiPoint2
{
    float x;
    float y;
};

struct NiPoint3
{
    NiPoint3() : x(0.0f), y(0.0f), z(0.0f) {}
    float x;
    float y;
    float z;

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
public:
    virtual NiObject* CreateClone(NiCloningProcess& cloning);
};

class BSOcclusionShape : public NiObject
{
public:
    BSOcclusionShape();
    ~BSOcclusionShape() override;
    void CopyTransformTo(BSOcclusionShape& destination, NiCloningProcess& cloning) const;

    NiPoint3 translation;
    NiMatrix3 rotation;
    std::uint32_t visibilityState;
    bool updateFacesOrVertices;
};

class BSOcclusionPlane : public BSOcclusionShape
{
public:
    static void* operator new(std::size_t bytes) { return PortalHeapObject::operator new(bytes); }

    BSOcclusionPlane()
    {
        translation.x = NiPoint3::kZeroPoint.x;
        translation.y = NiPoint3::kZeroPoint.y;
        translation.z = NiPoint3::kZeroPoint.z;
        size.x = 50.0f;
        size.y = 50.0f;
        rotation = NiMatrix3::kIdentityMatrix;
        visibilityState = 0;
        twoSided = true;
        unkF8[0] = 0;
        unkF8[1] = 0;
        unkF8[2] = 0;
        unkF8[3] = 0;
    }
    ~BSOcclusionPlane() override;
    NiObject* CreateClone(NiCloningProcess& cloning) override;

    NiPoint2 size;
    NiFrustumPlanes frustumPlanes;
    NiPoint3 corners[4];
    std::uint8_t edgeFlags[4];
    bool twoSided;
    std::uint64_t unkF8[4];
};
static_assert(sizeof(BSOcclusionPlane) == 0x118, "BSOcclusionPlane size");
