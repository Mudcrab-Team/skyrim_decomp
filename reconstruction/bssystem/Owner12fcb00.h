// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0xeb97a0 (bssystem/ArchiveFile): source copied, names replaced by placeholders.
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBinaryStream::seek, NiFile::seek: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); get_info's BufferInfo reduced to void*
// Function12fcb00, Owner12fcb00: GUESS(low) STANDIN
// Unk_0A, member, padding, handle, Owner12fcb00::Functioneb97a0: GUESS(low) STANDIN
#pragma once
#include "ArchiveFile.h"

class Owner12fcb00 : public NiFile
{
public:
    using NiFile::seek;
    void seek(std::int32_t a_numBytes) override;  // 02
    virtual std::uint32_t Unk_0A() const;  // 0A
    std::uint8_t padding[0x16c];
    bool Function12fcb00() const;
    std::uint32_t member;
    std::uint8_t padding178[528];
    void* handle;  // 180
};
