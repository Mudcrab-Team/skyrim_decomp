// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xebf6a0 BSFile::WriteString
// Adapted bodies: none
#include "BSFile_ebf6a0.h"

#include <cstring>

// Write a BSString payload (optionally including the null terminator) through the stream write callback.
std::uint32_t BSFile::WriteString(const BSString& str, bool includeNull)
{
    const std::uint32_t length = (str.length == 0xFFFFu)
        ? static_cast<std::uint32_t>(std::strlen(str.data))
        : str.length;
    const char* text = str.data ? str.data : "";
    std::uint32_t componentSize = 1;
    const std::uint32_t written = _writeFn(this, text, length + (includeNull ? 1u : 0u), &componentSize, 1);
    _absoluteCurrentPos += written;
    totalBytes170 += written;
    return written;
}
