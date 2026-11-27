// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFile, _absoluteCurrentPos, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// WriteWString: CRASHLOGGER_PDB(59818@2026.10.24)
// BSWString, data, length, WriteFn, totalBytes170, unknown000, unknown00C, unknown020: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct BSWString
{
    const wchar_t* data;    // 00
    std::uint16_t  length;  // 08
};
static_assert(offsetof(BSWString, length) == 0x08, "length offset");

class BSFile
{
public:
    using WriteFn = std::uint32_t (*)(BSFile*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    std::uint32_t WriteWString(const BSWString& str, bool includeNull);

    std::uint8_t  unknown000[0x08];     // 000
    std::uint32_t _absoluteCurrentPos;  // 008
    std::uint8_t  unknown00C[0x0C];     // 00C
    WriteFn       _writeFn;             // 018
    std::uint8_t  unknown020[0x150];    // 020
    std::uint32_t totalBytes170;        // 170
};
static_assert(offsetof(BSFile, _absoluteCurrentPos) == 0x08, "_absoluteCurrentPos offset");
static_assert(offsetof(BSFile, _writeFn) == 0x18, "_writeFn offset");
static_assert(offsetof(BSFile, totalBytes170) == 0x170, "totalBytes170 offset");
