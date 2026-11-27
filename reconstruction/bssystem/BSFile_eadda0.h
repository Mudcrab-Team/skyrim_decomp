// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFile, file: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReadFile: CRASHLOGGER_PDB(59818@2026.10.24)
// pos2C, unknown00, unknown30: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>

class BSFile
{
public:
    std::uint32_t ReadFile(void* buffer, std::uint32_t numBytes);

    std::uint8_t  unknown00[0x2C];  // 00
    std::uint32_t pos2C;            // 2C
    std::uint8_t  unknown30[0x08];  // 30
    std::FILE*    file;             // 38
};
static_assert(offsetof(BSFile, pos2C) == 0x2C, "pos2C offset");
static_assert(offsetof(BSFile, file) == 0x38, "file offset");
