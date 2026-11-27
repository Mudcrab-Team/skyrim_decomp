// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiObject, NiBinaryStream, BSStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream::ReadFn, NiBinaryStream::Read, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, BSStream::Functionee5310, BSStream::unk00, BSStream::objects, BSStream::unk228, BSStream::iStr: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiObject;

class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes,
        std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();

    void Read(std::uint32_t* a_value)
    {
        std::uint32_t size = sizeof(std::uint32_t);
        absoluteCurrentPos += readFn(this, a_value, sizeof(std::uint32_t), &size, 1);
    }

    std::uint32_t absoluteCurrentPos;
    std::uint32_t unk0C;
    ReadFn* readFn;
};
static_assert(sizeof(NiBinaryStream) == 0x18, "NiBinaryStream size");

class BSStream
{
public:
    NiObject* Functionee5310();

    std::uint8_t unk00[0x220];
    NiObject** objects;
    std::uint8_t unk228[0x70];
    NiBinaryStream* iStr;
};
static_assert(offsetof(BSStream, objects) == 0x220, "objects offset");
static_assert(offsetof(BSStream, iStr) == 0x298, "iStr offset");
