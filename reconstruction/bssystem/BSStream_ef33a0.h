// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, BSStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream::ReadFn, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, BSStream::Functionef33a0, BSStream::unk00, BSStream::iStr: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes,
        std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();

    std::uint32_t absoluteCurrentPos;
    std::uint32_t unk0C;
    ReadFn* readFn;
};
static_assert(sizeof(NiBinaryStream) == 0x18, "NiBinaryStream size");

class BSStream
{
public:
    void Functionef33a0(void* a_dest, std::uint32_t a_count);

    std::uint8_t unk00[0x298];
    NiBinaryStream* iStr;
};
static_assert(offsetof(BSStream, iStr) == 0x298, "iStr offset");
