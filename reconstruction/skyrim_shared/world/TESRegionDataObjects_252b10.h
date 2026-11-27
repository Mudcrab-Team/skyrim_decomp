// Source exposure: mixed (community headers; the pinned image listing; sibling decompilation shape).
// Code origin: adapted from the sibling decompilations; adapted bodies: TESRegionDataObjects::~TESRegionDataObjects.
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionDataObjects.cpp:113
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectrefr.cpp:18532
// TESRegionDataObjects, TESRegionData, TESRegionObjectList: EXE_RTTI
// ~TESRegionDataObjects: CRASHLOGGER_PDB(59818@2026.10.24)
// pObjects, bGeneratedObjects: SYMBOLS(fo4-pdb)
// TESRegionDataObjects, ~TESRegionDataObjects: SIBLING(fo4-private@1b765c70, author-permission)
// TESRegionObjectList, TESRegionData: STANDIN SIBLING(fo4-private@1b765c70, author-permission)
// unk08: GUESS(low); the qword between the vptr and the first member
#pragma once

#include <cstdint>
#include <cstddef>

class TESRegionObjectList
{
public:
    virtual ~TESRegionObjectList();
};

class TESRegionData
{
public:
    TESRegionData() {}
    virtual ~TESRegionData();

    void* unk08;  // 08
};

class TESRegionDataObjects : public TESRegionData
{
public:
    TESRegionDataObjects();
    virtual ~TESRegionDataObjects()  // compared: 0x252b10 (deleting form)
    {
        delete pObjects;
    }

    TESRegionObjectList* pObjects;  // 10
    bool bGeneratedObjects;         // 18
};
static_assert(sizeof(TESRegionDataObjects) == 0x20, "TESRegionDataObjects size");
