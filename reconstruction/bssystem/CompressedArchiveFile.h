// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing unit plus original reconstruction of archive stream helpers.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CompressedArchiveFile: EXE_RTTI
// NiBinaryStream, NiFile, good, seek, tell, get_info, set_endian_swap, size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_08, Unk_09, Unk_0A, padding08, readFn, writeFn, padding20, streamPtr, padding188, member, Functioneb9ef0, Functioneb9f10, Functioneb9f40: GUESS(low)
#pragma once
#include <cstdint>

class NiBinaryStream
{
public:
    virtual ~NiBinaryStream();  // 00
    virtual bool good() const;  // 01
    virtual void seek(std::int32_t a_numBytes);  // 02
    virtual std::uint32_t tell() const;  // 03
    virtual void get_info(void* a_buf);  // 04
    virtual void set_endian_swap(bool a_doSwap);  // 05
};

class NiFile : public NiBinaryStream
{
public:
    virtual void seek(std::int32_t a_offset, std::int32_t a_from);  // 06
    virtual std::uint32_t size() const;  // 07
    virtual void Unk_08();  // 08
    virtual void Unk_09();  // 09
};

class CompressedArchiveFile : public NiFile
{
public:
    using NiFile::seek;
    void seek(std::int32_t a_numBytes) override;  // 02
    virtual std::uint32_t Unk_0A() const;  // 0A
    std::uint32_t Functioneb9ef0() const;
    bool Functioneb9f10() const;
    void Functioneb9f40(bool a_doSwap);

    std::uint8_t padding08[0x8];  // 08
    void* readFn;  // 10
    void* writeFn;  // 18
    std::uint8_t padding20[0x160];  // 20
    void* streamPtr;  // 180
    std::uint8_t padding188[0x18];  // 188
    std::uint32_t member;  // 1A0
};
