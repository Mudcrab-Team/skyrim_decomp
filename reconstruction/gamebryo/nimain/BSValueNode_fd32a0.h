// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiBinaryStream::Read as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp:678
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:29
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, NiStream, NiNode, BSValueNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSValueNode::LoadBinary, BSValueNode::flags, BSValueNode::value: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream::ReadFn, NiBinaryStream::Read, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, NiStream::unk00, NiStream::iStr, NiNode::LoadBinary, NiNode::unk00, BSValueNode::unk129: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes,
        std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();

    template <class T>
    void Read(T* a_value)
    {
        std::uint32_t size = sizeof(T);
        absoluteCurrentPos += readFn(this, a_value, sizeof(T), &size, 1);
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

class NiNode
{
public:
    void LoadBinary(NiStream& a_stream);

    std::uint8_t unk00[0x128];
};
static_assert(sizeof(NiNode) == 0x128, "NiNode size");

class BSValueNode : public NiNode
{
public:
    void LoadBinary(NiStream& a_stream);

    std::uint8_t flags;
    std::uint8_t unk129[3];
    std::uint32_t value;
};
static_assert(offsetof(BSValueNode, flags) == 0x128, "flags offset");
static_assert(offsetof(BSValueNode, value) == 0x12C, "value offset");
