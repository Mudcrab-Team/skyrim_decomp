// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, NiStream, NiPSysModifier, BSPSysSubTexModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysSubTexModifier::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream::ReadFn, NiBinaryStream::Read, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, NiStream::unk00, NiStream::iStr, NiPSysModifier::LoadBinary, NiPSysModifier::unk00, BSPSysSubTexModifier::startFrame, BSPSysSubTexModifier::startFrameFudge, BSPSysSubTexModifier::endFrame, BSPSysSubTexModifier::loopStartFrame, BSPSysSubTexModifier::loopStartFrameFudge, BSPSysSubTexModifier::frameCount, BSPSysSubTexModifier::frameCountFudge: GUESS(low)
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
    void Read(T* a_value, std::uint32_t a_count = 1)
    {
        std::uint32_t size = sizeof(T);
        absoluteCurrentPos += readFn(this, a_value, sizeof(T) * a_count, &size, 1);
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

class NiPSysModifier
{
public:
    void LoadBinary(NiStream& a_stream);

    std::uint8_t unk00[0x30];
};
static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");

class BSPSysSubTexModifier : public NiPSysModifier
{
public:
    void LoadBinary(NiStream& a_stream);

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
