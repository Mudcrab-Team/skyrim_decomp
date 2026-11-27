// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, BSMultiBoundShape, BSMultiBoundSphere: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::DeleteThis, NiRefObject::ms_totalObjects: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::refCount, NiRefObject::unk0C, BSMultiBoundShape::unk10, BSMultiBoundShape::unk14, BSMultiBoundSphere::centerX, BSMultiBoundSphere::centerY, BSMultiBoundSphere::centerZ, BSMultiBoundSphere::radius: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject()
    {
        // atomic decrement of global live object counter on destruction
        _InterlockedDecrement(&ms_totalObjects);
    }
    virtual void DeleteThis();

    static long ms_totalObjects;

    long refCount;
    std::uint32_t unk0C;
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
    ~NiObject() override = default;
};

class BSMultiBoundShape : public NiObject
{
public:
    ~BSMultiBoundShape() override = default;

    std::uint32_t unk10;
    std::uint32_t unk14;
};
static_assert(sizeof(BSMultiBoundShape) == 0x18, "BSMultiBoundShape size");

class BSMultiBoundSphere : public BSMultiBoundShape
{
public:
    BSMultiBoundSphere();
    ~BSMultiBoundSphere() override = default;

    float centerX;
    float centerY;
    float centerZ;
    float radius;
};
static_assert(sizeof(BSMultiBoundSphere) == 0x28, "BSMultiBoundSphere size");
