// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSTerrainNode; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Flag_d5bcd2af.h"
struct BGSTerrainManager;
struct RE__BGSTerrainNode__Layer_RE__BGSDistantTreeBlock_efca2a28;
struct RE__BGSTerrainNode__Layer_RE__BGSObjectBlock_8b36c395;
struct RE__BGSTerrainNode__Layer_RE__BGSTerrainBlock_596ab1a7;
struct BGSTerrainNode {
    BGSTerrainManager* manager;
    RE__BGSTerrainNode__Layer_RE__BGSTerrainBlock_596ab1a7* terrain;
    RE__BGSTerrainNode__Layer_RE__BGSObjectBlock_8b36c395* objects;
    RE__BGSTerrainNode__Layer_RE__BGSDistantTreeBlock_efca2a28* trees;
    RE__BGSTerrainNode__Layer_RE__BGSTerrainBlock_596ab1a7* mapTerrain;
    RE__BGSTerrainNode__Layer_RE__BGSObjectBlock_8b36c395* mapObjects;
    unsigned char children_raw[8];
    BGSTerrainNode* parent;
    Flag_d5bcd2af nodeState;
    unsigned int nodeNumber;
    short baseCellX;
    short baseCellY;
    unsigned int pad4C;
};
static_assert(sizeof(BGSTerrainNode) == 80, "BGSTerrainNode layout differs from the PDB");
