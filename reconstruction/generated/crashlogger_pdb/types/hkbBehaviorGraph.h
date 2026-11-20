// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbBehaviorGraph; size 0x130
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkbBehaviorGraph__VFTable;
struct hkbNode__VFTable;
struct hkbBehaviorGraph {
    hkbBehaviorGraph__VFTable* vftable_hkbBehaviorGraph_0;
    hkbNode__VFTable* vftable_hkbNode_8;
    unsigned short m_memSizeAndFlags_10;
    short m_referenceCount_12;
    unsigned char variableMode;  // VariableMode in the PDB is wider than this slot
    unsigned char undefined_15[283];
};
static_assert(sizeof(hkbBehaviorGraph) == 304, "hkbBehaviorGraph layout differs from the PDB");
