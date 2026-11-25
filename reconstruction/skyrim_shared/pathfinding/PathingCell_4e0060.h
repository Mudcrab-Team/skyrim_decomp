// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Pathing/PathingCell.cpp:67
// PathingCell, Write, Info, WorldSpaceID, BSPathingStreamWrite, DoWriteNumericID: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// PathingCell, Write: CRASHLOGGER_PDB(59818@2026.10.24)
// DoWriteUInt, unk00, unk08, unk10, unk14, CellID: GUESS(low)
#pragma once

#include <cstdint>

class BSPathingStreamWrite
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void DoWriteUInt(std::uint32_t a_value);  // 05
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk10();
    virtual void DoWriteNumericID(std::uint32_t a_id);  // 11
};

struct PathingCellInfo
{
    std::uint32_t WorldSpaceID;  // 00
    std::uint32_t CellID;        // 04; also read as the cell key when the world space is set
};

class PathingCell
{
public:
    virtual void Write(BSPathingStreamWrite& a_stream) const;  // compared: 0x4e0060

    std::uint8_t unk08[8];
    PathingCellInfo Info;  // 10
};
static_assert(sizeof(PathingCell) == 0x18, "PathingCell size");
