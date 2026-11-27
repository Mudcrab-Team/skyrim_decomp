// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiBinaryStream::Read as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp:678
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitransform.cpp:19
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, NiStream, NiPoint3, NiRefObject, NiObject, BSMultiBoundShape, BSMultiBoundSphere: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3::x, NiPoint3::y, NiPoint3::z, BSMultiBoundShape::LoadBinary, BSMultiBoundSphere::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream::ReadFn, NiBinaryStream::Read, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, NiStream::unk00, NiStream::iStr, NiPoint3::LoadBinary, NiRefObject::unk00, BSMultiBoundShape::unk10, BSMultiBoundShape::unk14, BSMultiBoundSphere::center, BSMultiBoundSphere::radius: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes,
        std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();

    void Read(float* a_value)
    {
        std::uint32_t size = sizeof(float);
        absoluteCurrentPos += readFn(this, a_value, sizeof(float), &size, 1);
    }

    std::uint32_t absoluteCurrentPos;
    std::uint32_t unk0C;
    ReadFn* readFn;
};
static_assert(sizeof(NiBinaryStream) == 0x18, "NiBinaryStream size");

class NiStream
{
public:
    std::uint8_t unk00[0x298];
    NiBinaryStream* iStr;
};
static_assert(offsetof(NiStream, iStr) == 0x298, "iStr offset");

struct NiPoint3
{
    void LoadBinary(NiStream& a_stream);

    float x;
    float y;
    float z;
};

class NiRefObject
{
public:
    std::uint8_t unk00[0x10];
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
};

class BSMultiBoundShape : public NiObject
{
public:
    void LoadBinary(NiStream& a_stream);

    std::uint32_t unk10;
    std::uint32_t unk14;
};
static_assert(sizeof(BSMultiBoundShape) == 0x18, "BSMultiBoundShape size");

class BSMultiBoundSphere : public BSMultiBoundShape
{
public:
    void LoadBinary(NiStream& a_stream);

    NiPoint3 center;
    float radius;
};
static_assert(offsetof(BSMultiBoundSphere, center) == 0x18, "center offset");
static_assert(offsetof(BSMultiBoundSphere, radius) == 0x24, "radius offset");
static_assert(sizeof(BSMultiBoundSphere) == 0x28, "BSMultiBoundSphere size");
