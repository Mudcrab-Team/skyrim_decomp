// Source exposure: mixed (the pinned image listing; sibling shape).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSConstructFormsInAllFilesMap.cpp:146
// 0x1f9670 BGSConstructCellBlocksMap::~BGSConstructCellBlocksMap
// CI hash: 0x1f9670 ??1BGSConstructCellBlocksMap@@QEAA@XZ
#include "BGSConstructCellBlocksMap_1f9670.h"

BGSConstructCellBlocksMap::~BGSConstructCellBlocksMap()
{
    HashMapDeleter functor;
    table.KillTable(functor, true);
}
