// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// MovementMessageWarpToMultiple, Func2_1411040B0: CRASHLOGGER_PDB(59818@2026.10.24)
// MovementStreamWriter, MovementWarpEntry, WriteCount, WriteEntry, unk00, entries, capacity, size, Unk_01..Unk_03: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class MovementStreamWriter
{
public:
    virtual ~MovementStreamWriter();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void WriteCount(std::uint32_t count);  // 20
};

class MovementWarpEntry
{
public:
    virtual ~MovementWarpEntry();
    virtual void Unk_01();
    virtual void WriteEntry(MovementStreamWriter* writer);  // 10

    std::uint64_t unk08[9];  // 08
};
static_assert(sizeof(MovementWarpEntry) == 0x50, "MovementWarpEntry size");

class MovementMessageWarpToMultiple
{
public:
    void Func2_1411040B0(MovementStreamWriter* writer);

    std::uint64_t      unk00[2];  // 00
    MovementWarpEntry* entries;   // 10
    std::uint64_t      capacity;  // 18
    std::uint32_t      size;      // 20
};
static_assert(sizeof(MovementMessageWarpToMultiple) == 0x28, "MovementMessageWarpToMultiple size");
