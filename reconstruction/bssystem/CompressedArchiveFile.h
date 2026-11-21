// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// CompressedArchiveFile: EXE_RTTI
// Unk_0A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBinaryStream::good, NiBinaryStream::seek, NiBinaryStream::tell, NiBinaryStream::get_info, NiBinaryStream::set_endian_swap, NiFile::seek, NiFile::size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); get_info's BufferInfo reduced to void*
// NiFile::Unk_08, NiFile::Unk_09: GUESS(low); placeholders for slots 08 and 09 (NG declares them on BSFile)
#pragma once
#include <cstdint>
// Unk_0A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBinaryStream, NiFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); bases reduced to their virtual slots (BSFile omitted)
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
    std::uint8_t padding[0x198];
    std::uint32_t member;
};
