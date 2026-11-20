// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSKeywordForm__VFTable; size 0x30
#pragma once

struct BGSKeywordForm;
struct BGSKeyword_f67121b2;
struct BaseFormComponent_9d659514;
struct BGSKeywordForm__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    char (*HasKeyword_20)(BGSKeywordForm* , BGSKeyword_f67121b2* );
    long long (*GetDefaultKeyword_28)(void);
};
static_assert(sizeof(BGSKeywordForm__VFTable) == 48, "BGSKeywordForm__VFTable layout differs from the PDB");
