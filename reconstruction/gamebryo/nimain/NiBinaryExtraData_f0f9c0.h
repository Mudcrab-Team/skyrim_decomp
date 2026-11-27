// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, NiStream, NiExtraData, NiBinaryExtraData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryExtraData::LoadBinary_140C83C80: CRASHLOGGER_PDB(59818@2026.10.24)
// AllocBinaryPayload, NiBinaryStream::ReadFn, NiBinaryStream::Read, NiBinaryStream::ReadBytes, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, NiStream::unk00, NiStream::iStr, NiExtraData::LoadBinary, NiExtraData::unk00, NiBinaryExtraData::data, NiBinaryExtraData::size: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

std::uint8_t* AllocBinaryPayload(std::size_t a_size);

class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes,
        std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();

    template <class T>
    void Read(T* a_value, std::uint32_t a_count = 1)
    {
        std::uint32_t size = sizeof(T);
        absoluteCurrentPos += readFn(this, a_value, sizeof(T) * a_count, &size, 1);
    }

    void ReadBytes(void* a_buffer, std::uint32_t a_bytes)
    {
        std::uint32_t size = 1;
        absoluteCurrentPos += readFn(this, a_buffer, a_bytes, &size, 1);
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

class NiExtraData
{
public:
    void LoadBinary(NiStream& a_stream);

    std::uint8_t unk00[0x18];
};
static_assert(sizeof(NiExtraData) == 0x18, "NiExtraData size");

class NiBinaryExtraData : public NiExtraData
{
public:
    void LoadBinary_140C83C80(NiStream& a_stream);

    std::uint8_t* data;
    std::uint32_t size;
};
static_assert(offsetof(NiBinaryExtraData, data) == 0x18, "data offset");
static_assert(offsetof(NiBinaryExtraData, size) == 0x20, "size offset");
