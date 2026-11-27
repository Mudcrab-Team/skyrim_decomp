// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xebf620 BSFile::WriteWString
// Adapted bodies: none
#include "BSFile_ebf620.h"

#include <cstring>

// Write a wide-character string payload (optionally including its null terminator) through the write callback.
std::uint32_t BSFile::WriteWString(const BSWString& str, bool includeNull)
{
    const std::uint32_t length = (str.length == 0xFFFFu)
        ? static_cast<std::uint32_t>(wcslen(str.data))
        : str.length;
    const wchar_t* text = str.data ? str.data : L"";
    std::uint32_t componentSize = 1;
    const std::uint32_t byteCount = (length + (includeNull ? 1u : 0u)) * 2u;
    const std::uint32_t written = _writeFn(this, text, byteCount, &componentSize, 1);
    _absoluteCurrentPos += written;
    totalBytes170 += written;
    return written >> 1;
}
