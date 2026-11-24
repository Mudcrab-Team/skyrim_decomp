// Source exposure: mixed (community and sibling declarations, pinned image listing).
// Code origin: original reconstruction shaped after the cited sibling method; NiBinaryStream::write and binary_write follow CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderTextureSet, SaveBinary, textures, NiObject, NiStream, NiBinaryStream, iStr, oStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReadFn, WriteFn, _absoluteCurrentPos, _pad0C, _readFn, _writeFn, write, binary_write: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiStream, NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); fields and calls used by this unit
// unk00, unkStream: GUESS(low)
// WriteStreamString: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// Adapted bodies: BSShaderTextureSet::SaveBinary follows momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp:104
// Adapted bodies: NiBinaryStream::write and NiBinaryStream::binary_write from CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiBinaryStream.h and src/RE/N/NiBinaryStream.cpp (MIT)
#pragma once

#include <cstddef>
#include <cstdint>

class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    template <class T>
    bool write(const T* a_data, std::uint32_t a_count)
    {
        std::uint32_t size = sizeof(T);
        std::uint32_t toWrite = a_count * size;
        std::uint32_t bytesWritten = binary_write(a_data, toWrite, &size);
        return bytesWritten == toWrite;
    }

    std::uint32_t binary_write(const void* a_buffer, std::uint32_t a_totalBytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents = 1)
    {
        std::uint32_t bytesWritten = _writeFn(this, a_buffer, a_totalBytes, a_componentSizes, a_numComponents);
        _absoluteCurrentPos += bytesWritten;
        return bytesWritten;
    }

    std::uint64_t unk00;
    std::uint32_t _absoluteCurrentPos;
    std::uint32_t _pad0C;
    ReadFn* _readFn;
    WriteFn* _writeFn;
};

class NiStream
{
public:
    void WriteStreamString(const char* value);

    std::uint64_t unkStream[0x298 / 8];
    NiBinaryStream* iStr;
    NiBinaryStream* oStr;
};

class NiObject
{
public:
    virtual ~NiObject();
    virtual void SaveBinary(NiStream& stream);

private:
    std::uint64_t unk00;
};

class BSShaderTextureSet : public NiObject
{
public:
    void SaveBinary(NiStream& stream) override;

private:
    const char* textures[9];
};
