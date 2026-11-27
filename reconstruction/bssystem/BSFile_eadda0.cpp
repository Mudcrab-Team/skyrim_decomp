// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xeadda0 BSFile::ReadFile
// Adapted bodies: none
#include "BSFile_eadda0.h"

// Read bytes from the underlying C stream and advance the tracked stream offset.
std::uint32_t BSFile::ReadFile(void* buffer, std::uint32_t numBytes)
{
    const std::uint32_t bytesRead = static_cast<std::uint32_t>(std::fread(buffer, 1, numBytes, file));
    pos2C += bytesRead;
    return bytesRead;
}
