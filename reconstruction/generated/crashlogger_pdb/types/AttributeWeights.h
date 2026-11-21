// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AttributeWeights; size 0x3
#pragma once
struct AttributeWeights {
    unsigned char health;
    unsigned char magicka;
    unsigned char stamina;
};
static_assert(sizeof(AttributeWeights) == 3, "AttributeWeights layout differs from the PDB");
