// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: implementation based on the pinned game build; see Adapted bodies.
// Adapted bodies: NiBinaryStream::Write, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: CC0-1.0
// NiAlphaProperty, NiAlphaProperty::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiProperty, NiStream, NiBinaryStream, ostr, writeFn, position, flags, alphaThreshold: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiBinaryStream
{
    using WriteFn = std::uint32_t (*)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    std::uint64_t unk00;  // 00
    std::uint32_t position;  // 08
    std::uint32_t unk0C;  // 0C
    std::uint64_t unk10;  // 10
    WriteFn writeFn;  // 18

    void Write(const void* a_buffer, std::uint32_t a_bytes, std::uint32_t a_elemSize)
    {
        std::uint32_t sizes = a_elemSize;
        position += writeFn(this, a_buffer, a_bytes, &sizes, 1);
    }
};
static_assert(offsetof(NiBinaryStream, position) == 0x08, "position offset");
static_assert(offsetof(NiBinaryStream, writeFn) == 0x18, "writeFn offset");

struct NiStream
{
    std::uint8_t unk00[0x2A0];  // 00
    NiBinaryStream* ostr;  // 2A0
};
static_assert(offsetof(NiStream, ostr) == 0x2A0, "ostr offset");

class NiProperty
{
public:
    virtual ~NiProperty();
    void SaveBinary(NiStream& a_stream);

    std::uint8_t unk08[0x28];  // 08
};
static_assert(sizeof(NiProperty) == 0x30, "NiProperty size");

class NiAlphaProperty : public NiProperty
{
public:
    void SaveBinary(NiStream& a_stream);  // compared: 0xef28e0

    std::uint16_t flags;  // 30
    std::uint8_t alphaThreshold;  // 32
};
static_assert(offsetof(NiAlphaProperty, flags) == 0x30, "flags offset");
static_assert(offsetof(NiAlphaProperty, alphaThreshold) == 0x32, "alphaThreshold offset");
