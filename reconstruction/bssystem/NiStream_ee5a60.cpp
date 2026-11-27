// Source exposure: binary-analysis.
// Code origin: reconstructed from pinned-image observations; see Adapted bodies.
// Adapted bodies: NiStream::GetNextSearchPath, treated as adapted: the origin check reports similarity to the sibling body cited below (CC0-1.0).
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
