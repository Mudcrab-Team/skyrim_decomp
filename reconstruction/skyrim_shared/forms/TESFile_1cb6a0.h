// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESFile, TESFile::GetInteriorOffsetForCell, TESFile::interiorCellOffsetData, TESObjectCELL: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectCELL::formID, InteriorCellOffsetEntry, InteriorCellOffsetEntry::formID, InteriorCellOffsetEntry::unk04, InteriorCellOffsetEntry::offset, InteriorCellOffsetData, InteriorCellOffsetData::entries, InteriorCellOffsetData::unk08, InteriorCellOffsetData::count, TESFile::unk000, TESObjectCELL::unk00: GUESS(low); offsets observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class TESObjectCELL
{
public:
    std::uint8_t  unk00[0x14];  // 00
    std::uint32_t formID;       // 14
};
static_assert(offsetof(TESObjectCELL, formID) == 0x14, "TESObjectCELL::formID offset");

struct InteriorCellOffsetEntry
{
    std::uint32_t formID;  // 00
    std::uint32_t unk04;   // 04
    std::uint32_t offset;  // 08
};
static_assert(sizeof(InteriorCellOffsetEntry) == 0xC, "InteriorCellOffsetEntry size");

struct InteriorCellOffsetData
{
    InteriorCellOffsetEntry* entries;  // 00
    std::uint64_t            unk08;    // 08
    std::uint32_t            count;    // 10
};
static_assert(offsetof(InteriorCellOffsetData, count) == 0x10, "InteriorCellOffsetData::count offset");

class TESFile
{
public:
    std::uint32_t GetInteriorOffsetForCell(const TESObjectCELL* a_cell) const;

    std::uint8_t            unk000[0x4C0];           // 000
    InteriorCellOffsetData* interiorCellOffsetData;  // 4C0
};
static_assert(offsetof(TESFile, interiorCellOffsetData) == 0x4C0, "TESFile::interiorCellOffsetData offset");
