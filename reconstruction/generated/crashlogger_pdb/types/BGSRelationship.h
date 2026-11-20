// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSRelationship; size 0x40
#pragma once

#include "TESForm.h"
struct BGSAssociationType;
struct TESNPC;
struct BGSRelationship {
    TESForm _base;
    TESNPC* npc1;
    TESNPC* npc2;
    BGSAssociationType* assocType;
    unsigned char level;  // RELATIONSHIP_LEVEL in the PDB is wider than this slot
    unsigned char unk39;
    unsigned char unk3A;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned int pad3C;
};
static_assert(sizeof(BGSRelationship) == 64, "BGSRelationship layout differs from the PDB");
