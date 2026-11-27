// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiBinaryStream::Write as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitransform.cpp:25
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, NiStream, NiNode, BSValueNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSValueNode::SaveBinary, BSValueNode::flags, BSValueNode::value: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream::WriteFn, NiBinaryStream::Write, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, NiBinaryStream::writeFn, NiStream::unk00, NiStream::oStr, NiNode::SaveBinary, NiNode::unk00, BSValueNode::unk129: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiBinaryStream
{
public:
    using WriteFn = std::uint32_t(NiBinaryStream* a_this, const void* a_buffer, std::uint32_t a_bytes,
        std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();

    template <class T>
    void Write(const T* a_value)
    {
        std::uint32_t size = sizeof(T);
        absoluteCurrentPos += writeFn(this, a_value, sizeof(T), &size, 1);
    }

    std::uint32_t absoluteCurrentPos;
    std::uint32_t unk0C;
    void* readFn;
    WriteFn* writeFn;
};
static_assert(sizeof(NiBinaryStream) == 0x20, "NiBinaryStream size");

class NiStream
{
public:
    std::uint8_t unk00[0x2A0];
    NiBinaryStream* oStr;
};
static_assert(offsetof(NiStream, oStr) == 0x2A0, "oStr offset");

class NiNode
{
public:
    void SaveBinary(NiStream& a_stream);

    std::uint8_t unk00[0x128];
};
static_assert(sizeof(NiNode) == 0x128, "NiNode size");

class BSValueNode : public NiNode
{
public:
    void SaveBinary(NiStream& a_stream);

    std::uint8_t flags;
    std::uint8_t unk129[3];
    std::uint32_t value;
};
static_assert(offsetof(BSValueNode, flags) == 0x128, "flags offset");
static_assert(offsetof(BSValueNode, value) == 0x12C, "value offset");
