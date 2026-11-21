// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFlattenedBoneTree; size 0x168
#pragma once

#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_059ec2d1.h"
#include "NiNode.h"
struct BoneEntry;
struct BSFlattenedBoneTree {
    NiNode _base;
    unsigned int numBones;
    unsigned int numPopulatedBones;
    BoneEntry* boneEntries;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_059ec2d1 boneMap;
};
static_assert(sizeof(BSFlattenedBoneTree) == 360, "BSFlattenedBoneTree layout differs from the PDB");
