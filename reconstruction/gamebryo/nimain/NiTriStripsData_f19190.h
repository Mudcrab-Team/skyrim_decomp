// Source exposure: mixed (community declarations; CrashLogger names/layout; pinned-image observations).
// Code origin: original; declarations represented from the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTriStripsData, NiTriStripsData::GetBlockAllocationSize, numTriangles, activeTriangles, numStrips: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiObject::GetBlockAllocationSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown, unknown0C, unknown6C: GUESS(low) STANDIN; unaccessed storage extents.
// vtable, refCount: GUESS(medium) STANDIN; represented NiObject prefix.
#pragma once
#include <cstddef>
#include <cstdint>

class NiObject {
public:
    std::uint32_t GetBlockAllocationSize() const;
    void* vtable;
    std::uint32_t refCount;
    std::uint32_t unknown0C;
};
class NiTriStripsData : public NiObject {
public:
    std::uint32_t GetBlockAllocationSize() const;  // compared: 0xf19190
    std::uint8_t unknown[0x58];
    std::uint16_t numTriangles;
    std::uint16_t activeTriangles;
    std::uint32_t unknown6C;
    std::uint16_t numStrips;
};
static_assert(offsetof(NiTriStripsData, numTriangles) == 0x68, "observed triangle count offset");
static_assert(offsetof(NiTriStripsData, numStrips) == 0x70, "observed strip count offset");
