// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: GString121040::~GString121040, treated as adapted: shaped like GString::DataDesc::Release (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/G/GString.cpp:24, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x120e80 GMemoryFile::Read
// 0x121040 GMemoryFile::dtor
// CI hash: 0x121040 ??_GGMemoryFile@@UEAAPEAXI@Z
#include "GMemoryFile.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
GMemoryFile::GMemoryFile()
{
}

// Copies up to the requested number of bytes from the memory buffer into the output.
// The community name table calls this GMemoryFile::sub_140EC70C0 (a hint, not proof); Read is a guess.
std::int32_t GMemoryFile::Read(std::uint8_t* a_buf, std::int32_t a_bytes)
{
    if (fileIndex + a_bytes > fileSize)
    {
        a_bytes = fileSize - fileIndex;
    }

    if (a_bytes > 0)
    {
        std::memcpy(a_buf, fileData + fileIndex, a_bytes);
        fileIndex += a_bytes;
    }

    return a_bytes;
}
