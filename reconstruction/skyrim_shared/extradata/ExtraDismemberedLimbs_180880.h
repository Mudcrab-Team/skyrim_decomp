// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// ExtraDismemberedLimbs: EXE_RTTI
// ExtraDismemberedLimbs::RemoveLimb: CRASHLOGGER_PDB(59818@2026.10.24)
// ExtraDismemberedLimbs::unk00, ExtraDismemberedLimbs::dismemberedLimbs, DismemberedLimb, DismemberedLimb::unk00, DismemberedLimb::limbIndex, DismemberedLimb::unk19, DismemberedLimb::removed, DismemberedLimbArray, DismemberedLimbArray::data, DismemberedLimbArray::unk08, DismemberedLimbArray::size: GUESS(low); offsets observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

struct DismemberedLimb
{
    std::uint8_t unk00[0x18];  // 00
    std::uint8_t limbIndex;    // 18
    std::uint8_t unk19[0x2];   // 19
    bool         removed;      // 1B
};
static_assert(offsetof(DismemberedLimb, limbIndex) == 0x18, "DismemberedLimb::limbIndex offset");
static_assert(offsetof(DismemberedLimb, removed) == 0x1B, "DismemberedLimb::removed offset");

struct DismemberedLimbArray
{
    DismemberedLimb** data;   // 00
    std::uint64_t     unk08;  // 08
    std::uint32_t     size;   // 10
};
static_assert(offsetof(DismemberedLimbArray, size) == 0x10, "DismemberedLimbArray::size offset");

class ExtraDismemberedLimbs
{
public:
    void RemoveLimb(std::uint32_t a_limbIndex, bool a_removed);

    std::uint8_t         unk00[0x20];       // 00
    DismemberedLimbArray dismemberedLimbs;  // 20
};
static_assert(offsetof(ExtraDismemberedLimbs, dismemberedLimbs) == 0x20, "ExtraDismemberedLimbs::dismemberedLimbs offset");
