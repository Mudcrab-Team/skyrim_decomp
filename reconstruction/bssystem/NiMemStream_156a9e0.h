// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation and partial layouts from the pinned accesses and cited declarations.
// NiMemStream: EXE_RTTI
// get_info, seek: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiMemStream::buffer, ::position, ::length, ::capacity, ::externalBuffer, ::released, ::ReleaseBuffer, ::ReadBytes: GUESS(low)
#pragma once

#include <cstdint>

// NiBinaryStream, NiBinaryStream::BufferInfo, ::good, ::seek, ::tell, ::get_info, ::set_endian_swap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiBinaryStream
{
public:
    struct BufferInfo
    {
        void* buffer;
        std::uint32_t totalSize;
        std::uint32_t bufferAllocSize;
        std::uint32_t bufferReadSize;
        std::uint32_t bufferPos;
        std::uint32_t streamPos;
        std::uint32_t padding;
    };

    using Reader = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using Writer = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    virtual ~NiBinaryStream();
    virtual bool good() const;
    virtual void seek(std::int32_t offset);
    virtual std::uint32_t tell() const;
    virtual void get_info(BufferInfo& info);
    virtual void set_endian_swap(bool enabled);

protected:
    std::uint32_t absoluteCurrentPos;
    std::uint32_t padding0C;
    Reader* readFn;
    Writer* writeFn;
};
static_assert(sizeof(NiBinaryStream) == 0x20, "binary stream prefix size");

class NiMemStream : public NiBinaryStream
{
public:
    ~NiMemStream() override;
    void get_info(BufferInfo& info) override;
    void seek(std::int32_t delta) override;
    void* ReleaseBuffer();
    std::uint32_t ReadBytes(void* destination, std::uint32_t count);

private:
    unsigned char* buffer;
    std::uint32_t position;
    std::uint32_t length;
    std::uint32_t capacity;
    bool externalBuffer;
    bool released;
};
