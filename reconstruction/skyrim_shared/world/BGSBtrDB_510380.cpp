// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x510380 BGSBtrDB::DBTraits::ArgsType::operator=
// CI hash: 0x510380 ??4ArgsType@DBTraits@BGSBtrDB@@QEAAAEBV012@AEBV012@@Z
// Adapted bodies: BGSBtrDB::DBTraits::ArgsType::operator= from fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainChunk.cpp:46 (see the header)
#include "BGSBtrDB_510380.h"

const BGSBtrDB::DBTraits::ArgsType& BGSBtrDB::DBTraits::ArgsType::operator=(const BGSBtrDB::DBTraits::ArgsType& a_rhs)
{
    pNode = a_rhs.pNode;
    iCellX = a_rhs.iCellX;
    iCellY = a_rhs.iCellY;
    void* newDiffuse = const_cast<ArgsType&>(a_rhs).Diffuse.pEntry;
    void* oldDiffuse = Diffuse.pEntry;
    if (newDiffuse != oldDiffuse)
    {
        const_cast<ArgsType&>(a_rhs).Diffuse.pEntry = nullptr;
        Diffuse.pEntry = newDiffuse;
        Diffuse.Release(oldDiffuse);
    }
    void* newNormal = const_cast<ArgsType&>(a_rhs).Normal.pEntry;
    void* oldNormal = Normal.pEntry;
    if (newNormal != oldNormal)
    {
        const_cast<ArgsType&>(a_rhs).Normal.pEntry = nullptr;
        Normal.pEntry = newNormal;
        Normal.Release(oldNormal);
    }
    return *this;
}
