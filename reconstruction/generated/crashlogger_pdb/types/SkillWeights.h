// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SkillWeights; size 0x12
#pragma once
struct SkillWeights {
    unsigned char oneHanded;
    unsigned char twoHanded;
    unsigned char archery;
    unsigned char block;
    unsigned char smithing;
    unsigned char heavyArmor;
    unsigned char lightArmor;
    unsigned char pickpocket;
    unsigned char lockpicking;
    unsigned char sneak;
    unsigned char alchemy;
    unsigned char speech;
    unsigned char alteration;
    unsigned char conjuration;
    unsigned char destruction;
    unsigned char illusion;
    unsigned char restoration;
    unsigned char enchanting;
};
static_assert(sizeof(SkillWeights) == 18, "SkillWeights layout differs from the PDB");
