// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPathingCell, BSPathingLocation: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingLocation::QValid, BSPathingLocation::pathingCell, BSPathingLocation::flags: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingCell::Unk_00, BSPathingCell::Unk_01, BSPathingCell::Unk_02, BSPathingCell::Unk_03, BSPathingCell::Unk_04, BSPathingCell::Unk_05, BSPathingCell::Unk_06, BSPathingCell::Unk_07, BSPathingLocation::unk00, BSPathingLocation::unk28, BSPathingLocation::unk2B: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSPathingCell
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual bool Unk_07();
};

class BSPathingLocation
{
public:
    bool QValid() const;

    std::uint8_t unk00[0x20];
    BSPathingCell* pathingCell;
    std::uint16_t unk28;
    std::uint8_t flags;
    std::uint8_t unk2B[5];
};
static_assert(offsetof(BSPathingLocation, pathingCell) == 0x20, "pathingCell offset");
static_assert(offsetof(BSPathingLocation, flags) == 0x2A, "flags offset");
static_assert(sizeof(BSPathingLocation) == 0x30, "BSPathingLocation size");
