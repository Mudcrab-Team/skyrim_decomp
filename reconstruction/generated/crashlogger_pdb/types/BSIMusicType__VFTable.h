// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIMusicType__VFTable; size 0x40
#pragma once

struct BSIMusicType;
struct BSIMusicType__VFTable {
    int (*DoUpdate_0)(void);
    int (*DoPlay_8)(void);
    int (*DoPause_10)(void);
    int (*DoFinish_18)(void);
    void (*DoApplyDuckingAttenuation_20)(void);
    void (*DoClearDucking_28)(void);
    void (*DoPrepare_30)(void);
    long long (*dtor_38)(BSIMusicType* , char);
};
static_assert(sizeof(BSIMusicType__VFTable) == 64, "BSIMusicType__VFTable layout differs from the PDB");
