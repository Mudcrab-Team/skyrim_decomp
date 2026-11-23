// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFile, NiFile::get_info: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

// FileInfo and its members, NiFile members and virtual slots: GUESS(low)
struct FileInfo
{
    uint64_t unk00;
    uint32_t unk08;
    uint32_t unk0C;
    uint32_t unk10;
    uint32_t unk14;
    uint32_t unk18;
};

class NiFile
{
public:
    virtual ~NiFile();
    virtual void unk01();
    virtual void unk02();
    virtual uint32_t unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual uint32_t unk07();

    void get_info(FileInfo* a_info);

    unsigned char pad08[0x18];
    uint32_t unk20;
    uint32_t unk24;
    uint32_t unk28;
    unsigned char pad2C[0x4];
    uint64_t unk30;
};
