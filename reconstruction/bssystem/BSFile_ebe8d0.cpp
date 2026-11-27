// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xebe8d0 BSFile::UpdateFileSize
// Adapted bodies: none
#include "BSFile_ebe8d0.h"

// Flush write buffers if open for writing, then measure and cache the underlying stream length.
std::uint32_t BSFile::UpdateFileSize()
{
    fileSize = 0;
    if (openMode == 1) {
        FlushBuffer();
    }
    Seek(0, 0);
    if (file) {
        const long currentPos = std::ftell(file);
        std::fseek(file, 0, SEEK_END);
        fileSize = static_cast<std::uint32_t>(std::ftell(file));
        std::fseek(file, currentPos, SEEK_SET);
    }
    return fileSize;
}
