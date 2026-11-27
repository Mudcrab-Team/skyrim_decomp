// Source exposure: binary-analysis.
// Code origin: reconstructed from pinned-image observations; see Adapted bodies.
// Adapted bodies: NiStream::GetNextSearchPath, treated as adapted: the origin check reports similarity to the sibling body cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nistream.cpp:359
// SPDX-License-Identifier: CC0-1.0
// NiStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream::GetNextSearchPath: CRASHLOGGER_PDB(59818@2026.10.24)
// gSearchPathAvailable, NiStream::unk00, NiStream::searchPath: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern bool gSearchPathAvailable;

class NiStream
{
public:
    bool GetNextSearchPath(char* a_dest, std::uint32_t a_destSize);

    std::uint8_t unk00[0x518];
    char searchPath[260];
};
static_assert(offsetof(NiStream, searchPath) == 0x518, "searchPath offset");
