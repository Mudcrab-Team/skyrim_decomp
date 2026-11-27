// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, NiStream, NiPSysModifier, BSPSysLODModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysLODModifier::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream::WriteFn, NiBinaryStream::Write, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, NiBinaryStream::writeFn, NiStream::unk00, NiStream::oStr, NiPSysModifier::SaveBinary, NiPSysModifier::unk00, BSPSysLODModifier::lodBeginDistance, BSPSysLODModifier::lodEndDistance, BSPSysLODModifier::endEmitScale, BSPSysLODModifier::endSize: GUESS(low)
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
    void Write(const T* a_value, std::uint32_t a_count = 1)
    {
        std::uint32_t size = sizeof(T);
        absoluteCurrentPos += writeFn(this, a_value, sizeof(T) * a_count, &size, 1);
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

class NiPSysModifier
{
public:
    void SaveBinary(NiStream& a_stream);

    std::uint8_t unk00[0x30];
};
static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");

class BSPSysLODModifier : public NiPSysModifier
{
public:
    void SaveBinary(NiStream& a_stream);

    float lodBeginDistance;
    float lodEndDistance;
    float endEmitScale;
    float endSize;
};
static_assert(offsetof(BSPSysLODModifier, lodBeginDistance) == 0x30, "lodBeginDistance offset");
static_assert(offsetof(BSPSysLODModifier, endSize) == 0x3C, "endSize offset");
