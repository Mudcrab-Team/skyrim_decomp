// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xebf590 BSFile::ReadUntil
// Adapted bodies: none
#include "BSFile_ebf590.h"

// Read bytes one at a time into a null-terminated buffer until the delimiter, EOF, or buffer capacity.
std::uint32_t BSFile::ReadUntil(char* buffer, std::uint32_t bufferSize, wchar_t delimiter)
{
    std::uint32_t totalRead = 0;
    std::uint32_t outIndex = 0;
    while (outIndex + 1u < bufferSize) {
        char ch;
        const std::uint32_t count = ReadBytes(&ch, 1);
        totalRead += count;
        if (count != 1u || ch == delimiter) {
            break;
        }
        buffer[outIndex++] = ch;
    }
    buffer[outIndex] = 0;
    return totalRead;
}
