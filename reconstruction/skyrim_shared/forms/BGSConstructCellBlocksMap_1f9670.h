// Source exposure: mixed (sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSConstructFormsInAllFilesMap.cpp:146
// BGSConstructCellBlocksMap, BGSConstructCellBlocksMap::~BGSConstructCellBlocksMap, BGSConstructCellSubBlocksMap: SIBLING(fo4-private@1b765c70, author-permission)
// HashMapDeleter, KillTable: GUESS(medium); the names the sibling body uses
// CellBlocksTable, table, unknown00: GUESS(low); the sibling derives from a scatter table, modelled here as a member
#pragma once

#include <cstdint>

class BGSConstructCellSubBlocksMap;

struct HashMapDeleter
{
};

struct CellBlocksTable
{
    ~CellBlocksTable();
    void KillTable(HashMapDeleter& a_functor, bool a_free);

    std::uint8_t unknown00[0x28];  // 00
};

class BGSConstructCellBlocksMap
{
public:
    ~BGSConstructCellBlocksMap();  // compared: 0x1f9670

    std::uint64_t unknown00;  // 00
    CellBlocksTable table;  // 08
};
