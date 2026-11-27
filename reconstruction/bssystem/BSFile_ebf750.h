// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFile, size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UpdateFileSize, fileSize, Unk_01..Unk_09, unknown008: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class BSFile
{
public:
    virtual ~BSFile();                // 00
    virtual void Unk_01();            // 01
    virtual void Unk_02();            // 02
    virtual void Unk_03();            // 03
    virtual void Unk_04();            // 04
    virtual void Unk_05();            // 05
    virtual void Unk_06();            // 06
    virtual void Unk_07();            // 07
    virtual void Unk_08();            // 08
    virtual void Unk_09();            // 09
    virtual std::uint32_t UpdateFileSize();    // 0A (0x50)

    std::uint32_t size();

    std::uint8_t  unknown008[0x16C];  // 008
    std::uint32_t fileSize;           // 174
};
static_assert(offsetof(BSFile, fileSize) == 0x174, "fileSize offset");
