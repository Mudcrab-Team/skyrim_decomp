// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, BSStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiAlloc, NiBinaryStream::ReadFn, NiBinaryStream::ReadInt, NiBinaryStream::ReadBytes, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, BSStream::Functionee4820, BSStream::unk00, BSStream::iStr: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

char* NiAlloc(std::size_t a_bytes);

class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes,
        std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();

    void ReadInt(std::int32_t* a_value)
    {
        std::uint32_t size = sizeof(std::int32_t);
        absoluteCurrentPos += readFn(this, a_value, sizeof(std::int32_t), &size, 1);
    }

    void ReadBytes(char* a_buffer, std::uint32_t a_count)
    {
        std::uint32_t size = 1;
        absoluteCurrentPos += readFn(this, a_buffer, a_count, &size, 1);
    }

    std::uint32_t absoluteCurrentPos;
    std::uint32_t unk0C;
    ReadFn* readFn;
};
static_assert(sizeof(NiBinaryStream) == 0x18, "NiBinaryStream size");

class BSStream
{
public:
    void Functionee4820(char*& a_out);

    std::uint8_t unk00[0x298];
    NiBinaryStream* iStr;
};
static_assert(offsetof(BSStream, iStr) == 0x298, "iStr offset");
