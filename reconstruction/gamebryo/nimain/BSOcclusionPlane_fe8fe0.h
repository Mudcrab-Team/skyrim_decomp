// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: NiPoint3::operator- (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiPoint3.cpp, MIT; notice in the SPDX line below); NiPoint3::operator= (sibling similarity noted below).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/tile_ob1_variant.cpp:1386 (NiPoint3::operator-).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderbloodsplatter.cpp:258 (NiPoint3::operator-).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380 (NiPoint3::operator=, component-wise copy).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSOcclusionPlane, BSOcclusionShape, InsidePlanes, UpdateCorners, QuadIntersectsPlanes, NiPoint3, NiPoint2, NiMatrix3, NiFrustumPlanes, NiPlane, translation, rotation, visibilityState, updateFacesOrVertices, size, frustumPlanes, corners, edgeFlags, twoSided, unkF8: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiRefObject: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// normal, constant, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_frustumPlanes, refCount, unk0C: GUESS(low)
#pragma once

#include <cstdint>

struct NiPoint2
{
    float x;
    float y;
};

struct NiPoint3
{
    NiPoint3() : x(0.0f), y(0.0f), z(0.0f) {}
    NiPoint3(float a_x, float a_y, float a_z) : x(a_x), y(a_y), z(a_z) {}
    float x;
    float y;
    float z;

    NiPoint3 operator-(const NiPoint3& rhs) const
    {
        return NiPoint3(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    NiPoint3& operator=(const NiPoint3& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }
};

struct NiMatrix3
{
    float entry[3][3];
};

struct NiPlane
{
    NiPoint3 normal;
    float constant;
};

struct NiFrustumPlanes
{
    bool QuadIntersectsPlanes(const NiPoint3* corners, std::uint8_t* edgeFlags) const;

    NiPlane cullingPlanes[6];
    std::uint32_t activePlanes;
    std::uint32_t basePlaneStates;
    std::uint32_t unk68;
    std::uint32_t unk6C;
};

extern NiFrustumPlanes g_frustumPlanes;

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
    NiPoint3 translation;
    NiMatrix3 rotation;
    std::uint32_t visibilityState;
    bool updateFacesOrVertices;
};

class BSOcclusionPlane : public BSOcclusionShape
{
public:
    bool InsidePlanes(const NiPoint3& origin);
    void UpdateCorners();

    NiPoint2 size;
    NiFrustumPlanes frustumPlanes;
    NiPoint3 corners[4];
    std::uint8_t edgeFlags[4];
    bool twoSided;
    std::uint64_t unkF8[4];
};
static_assert(sizeof(BSOcclusionPlane) == 0x118, "BSOcclusionPlane size");
