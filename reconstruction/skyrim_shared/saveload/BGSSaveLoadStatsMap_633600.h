// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Adapted bodies: none
// BGSSaveLoadStatsMap, BGSSaveLoadStatsMap::CloseFile: CRASHLOGGER_PDB(59818@2026.10.24)
// StatsMapFile, file, unk00: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class StatsMapFile
{
public:
    virtual ~StatsMapFile();
};

class BGSSaveLoadStatsMap
{
public:
    void CloseFile();

    std::uint8_t unk00[0x30];
    StatsMapFile* file;
};
static_assert(offsetof(BGSSaveLoadStatsMap, file) == 0x30, "BGSSaveLoadStatsMap::file offset");
