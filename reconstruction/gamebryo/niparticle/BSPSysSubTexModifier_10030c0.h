// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, NiStream, NiPSysModifier, BSPSysSubTexModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysSubTexModifier::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream::WriteFn, NiBinaryStream::Write, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, NiBinaryStream::writeFn, NiStream::unk00, NiStream::oStr, NiPSysModifier::SaveBinary, NiPSysModifier::unk00, BSPSysSubTexModifier::startFrame, BSPSysSubTexModifier::startFrameFudge, BSPSysSubTexModifier::endFrame, BSPSysSubTexModifier::loopStartFrame, BSPSysSubTexModifier::loopStartFrameFudge, BSPSysSubTexModifier::frameCount, BSPSysSubTexModifier::frameCountFudge: GUESS(low)
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

class BSPSysSubTexModifier : public NiPSysModifier
{
public:
    void SaveBinary(NiStream& a_stream);

    float startFrame;
    float startFrameFudge;
    float endFrame;
    float loopStartFrame;
    float loopStartFrameFudge;
    float frameCount;
    float frameCountFudge;
};
static_assert(offsetof(BSPSysSubTexModifier, startFrame) == 0x30, "startFrame offset");
static_assert(offsetof(BSPSysSubTexModifier, frameCountFudge) == 0x48, "frameCountFudge offset");
