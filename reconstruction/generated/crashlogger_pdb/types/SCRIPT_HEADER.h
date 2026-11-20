// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SCRIPT_HEADER; size 0x14
#pragma once
struct SCRIPT_HEADER {
    unsigned int variableCount;
    unsigned int refObjectCount;
    unsigned int dataSize;
    unsigned int lastID;
    bool isQuestScript;
    bool isMagicEffectScript;
    bool isCompiled;
    unsigned char pad13;
};
static_assert(sizeof(SCRIPT_HEADER) == 20, "SCRIPT_HEADER layout differs from the PDB");
