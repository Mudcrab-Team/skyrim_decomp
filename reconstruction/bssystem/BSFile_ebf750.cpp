// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xebf750 BSFile::size
// Adapted bodies: none
#include "BSFile_ebf750.h"

// Return the cached file size, querying the file size virtually if not yet populated.
std::uint32_t BSFile::size()
{
    if (fileSize == 0) {
        UpdateFileSize();
    }
    return fileSize;
}
