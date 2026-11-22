// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ArchiveFile: EXE_RTTI
// Unk_0A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SEEK_CUR: GUESS(low); the relative-seek origin passed as 1
// 0xeb9780 ArchiveFile::Unk_0A
// 0xeb96e0 ArchiveFile::seek(std::int32_t)
// NiBinaryStream::seek: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); this override forwards to NiFile::seek
#include "ArchiveFile.h"
// Unk_0A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t ArchiveFile::Unk_0A() const
{
    return member;
}


void ArchiveFile::seek(std::int32_t a_numBytes)
{
    seek(a_numBytes, 1);
}
