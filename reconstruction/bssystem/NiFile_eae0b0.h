// Source exposure: mixed (community declarations, sibling spelling and pinned image).
// Code origin: Stand-in declarations from the labelled sources and the pinned image layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFile, NiFile::~NiFile, NiBinaryStream, NiBinaryStream::~NiBinaryStream, buffer, file, isGood: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiFile::Flush: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// NiFree: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08, unk20, unk40: GUESS(low)
#pragma once

#include <cstdint>

// _iobuf: OBSERVED; opaque MSVC CRT stream handle.
struct _iobuf;

class NiBinaryStream
{
public:
    virtual ~NiBinaryStream();

private:
    std::uint8_t unk08[0x18];
};

class NiFile : public NiBinaryStream
{
public:
    NiFile();
    ~NiFile() override;

private:
    bool Flush() noexcept;

    std::uint8_t unk20[0x10];
    char* buffer;
    _iobuf* file;
    std::uint32_t unk40;
    bool isGood;
};
static_assert(sizeof(NiFile) == 0x48, "NiFile size");

void NiFree(void* memory);
