// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSTerrainBlock; size 0x88
#pragma once

struct BGSTerrainNode_bd9493dd;
struct BSMultiBoundNode;
struct BSTriShape;
struct BGSTerrainBlock {
    BGSTerrainNode_bd9493dd* node;
    BSTriShape* land;
    BSMultiBoundNode* water;
    BSMultiBoundNode* chunk;
    bool loaded;
    bool attached;
    bool waterAttached;
    bool unk23;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned long long unk30;
    unsigned long long unk38;
    unsigned long long unk40;
    unsigned long long unk48;
    unsigned long long unk50;
    unsigned long long unk58;
    unsigned long long unk60;
    unsigned long long unk68;
    unsigned long long unk70;
    unsigned long long unk78;
    bool unk80;
    bool unk81;
    bool unk82;
    bool unk83;
    unsigned char undefined_84[4];
};
static_assert(sizeof(BGSTerrainBlock) == 136, "BGSTerrainBlock layout differs from the PDB");
