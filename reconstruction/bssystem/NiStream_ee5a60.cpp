// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiStream::GetNextSearchPath as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nistream.cpp:359
// SPDX-License-Identifier: CC0-1.0
// NiStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream::GetNextSearchPath: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xee5a60 NiStream::GetNextSearchPath
#include "NiStream_ee5a60.h"

#include <cstring>

// Copy the stored search path once when available and mark it consumed.
bool NiStream::GetNextSearchPath(char* a_dest, std::uint32_t)
{
    if (gSearchPathAvailable) {
        strncpy_s(a_dest, 260, searchPath, 259);
        gSearchPathAvailable = false;
        return true;
    }
    return false;
}
