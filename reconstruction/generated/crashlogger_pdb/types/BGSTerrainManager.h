// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSTerrainManager; size 0xd0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BGSTerrainNode_eacff7c8.h"
struct BGSTerrainNode;
struct TESWorldSpace_f9563d31;
struct BGSTerrainManager {
    unsigned long long unk00;
    TESWorldSpace_f9563d31* worldSpace;
    BGSTerrainNode* rootNode;
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
    BSTArray_RE__BGSTerrainNode_eacff7c8 updateNodes;
    unsigned int nextUpdateNode;
    unsigned int unk7C;
    BSTArray_RE__BGSTerrainNode_eacff7c8 immediateUpdates;
    unsigned long long unk98;
    unsigned long long unkA0;
    unsigned long long unkA8;
    unsigned long long unkB0;
    unsigned long long unkB8;
    unsigned long long unkC0;
    unsigned long long unkC8;
};
static_assert(sizeof(BGSTerrainManager) == 208, "BGSTerrainManager layout differs from the PDB");
