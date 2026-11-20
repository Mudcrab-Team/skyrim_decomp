// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSTerrainManager; size 0xd0
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BGSTerrainNode_eacff7c8_73f8bfb2.h"
struct BGSTerrainNode_bd9493dd;
struct TESWorldSpace;
struct BGSTerrainManager_f525841a {
    unsigned long long unk00;
    TESWorldSpace* worldSpace;
    BGSTerrainNode_bd9493dd* rootNode;
    short minCellX;
    short minCellY;
    unsigned int maxLevel;
    unsigned int minLevel;
    unsigned int rootLevel;
    unsigned int segmentedBlockLevel;
    unsigned int treeLevel;
    bool unk30;
    unsigned char unk31;
    bool lodTreesHidden;
    unsigned char unk33;
    bool needsImmediateUpdate;
    unsigned char unk35;
    bool hasLOD;
    unsigned char unk37;
    unsigned long long unk38;
    unsigned long long unk40;
    unsigned long long unk48;
    unsigned long long unk50;
    unsigned long long unk58;
    BSTArray_RE__BGSTerrainNode_eacff7c8_73f8bfb2 updateNodes;
    unsigned int nextUpdateNode;
    unsigned int unk7C;
    BSTArray_RE__BGSTerrainNode_eacff7c8_73f8bfb2 immediateUpdates;
    unsigned long long unk98;
    unsigned long long unkA0;
    unsigned long long unkA8;
    unsigned long long unkB0;
    unsigned long long unkB8;
    unsigned long long unkC0;
    unsigned long long unkC8;
};
static_assert(sizeof(BGSTerrainManager_f525841a) == 208, "BGSTerrainManager_f525841a layout differs from the PDB");
