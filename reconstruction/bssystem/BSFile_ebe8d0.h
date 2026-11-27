// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFile, file: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UpdateFileSize, FlushBuffer: CRASHLOGGER_PDB(59818@2026.10.24)
// Seek, openMode, fileSize, Unk_01..Unk_07, unknown008, unknown044: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>

class BSFile
{
public:
    virtual ~BSFile();                                     // 00
    virtual void Unk_01();                                 // 01
    virtual void Unk_02();                                 // 02
    virtual void Unk_03();                                 // 03
    virtual void Unk_04();                                 // 04
    virtual void Unk_05();                                 // 05
    virtual void Unk_06();                                 // 06
    virtual void Unk_07();                                 // 07
    virtual void Seek(std::int32_t offset, std::int32_t origin);  // 08 (0x40)

    bool          FlushBuffer();
    std::uint32_t UpdateFileSize();

    std::uint8_t  unknown008[0x30];   // 008
    std::FILE*    file;               // 038
    std::uint32_t openMode;           // 040
    std::uint8_t  unknown044[0x130];  // 044
    std::uint32_t fileSize;           // 174
};
static_assert(offsetof(BSFile, file) == 0x38, "file offset");
static_assert(offsetof(BSFile, openMode) == 0x40, "openMode offset");
static_assert(offsetof(BSFile, fileSize) == 0x174, "fileSize offset");
