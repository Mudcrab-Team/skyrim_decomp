// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AlchemyItem__AlchemyItemData; size 0x20
#pragma once

struct BGSSoundDescriptorForm_de361764;
struct SpellItem;
struct AlchemyItem__AlchemyItemData {
    int CostOverride_0;
    unsigned int Flags_4;
    SpellItem* AddictionItem_8;
    float AddictionChance_10;
    char _pad_14[4];
    BGSSoundDescriptorForm_de361764* ConsumptionSound_18;
};
static_assert(sizeof(AlchemyItem__AlchemyItemData) == 32, "AlchemyItem__AlchemyItemData layout differs from the PDB");
