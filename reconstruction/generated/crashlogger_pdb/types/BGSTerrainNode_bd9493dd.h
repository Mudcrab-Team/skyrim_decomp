// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSTerrainNode; size 0x50
// one of 2 different PDB types sharing this name
#pragma once

#include "Flag_a4a94b8a.h"
struct BGSTerrainManager_f525841a;
struct RE__BGSTerrainNode__Layer_RE__BGSDistantTreeBlock_efca2a28;
struct RE__BGSTerrainNode__Layer_RE__BGSObjectBlock_8b36c395;
struct RE__BGSTerrainNode__Layer_RE__BGSTerrainBlock_596ab1a7;
struct BGSTerrainNode_bd9493dd {
    BGSTerrainManager_f525841a* manager;
    RE__BGSTerrainNode__Layer_RE__BGSTerrainBlock_596ab1a7* terrain;
    RE__BGSTerrainNode__Layer_RE__BGSObjectBlock_8b36c395* objects;
    RE__BGSTerrainNode__Layer_RE__BGSDistantTreeBlock_efca2a28* trees;
    RE__BGSTerrainNode__Layer_RE__BGSTerrainBlock_596ab1a7* mapTerrain;
    RE__BGSTerrainNode__Layer_RE__BGSObjectBlock_8b36c395* mapObjects;
    unsigned char children_raw[8];
    BGSTerrainNode_bd9493dd* parent;
    Flag_a4a94b8a nodeState;
    unsigned int nodeNumber;
    short baseCellX;
    short baseCellY;
    unsigned int pad4C;
};
static_assert(sizeof(BGSTerrainNode_bd9493dd) == 80, "BGSTerrainNode_bd9493dd layout differs from the PDB");
