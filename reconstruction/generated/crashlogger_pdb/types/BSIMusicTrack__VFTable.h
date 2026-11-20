// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIMusicTrack__VFTable; size 0x58
#pragma once

struct BSIMusicTrack_879dae29;
struct BSIMusicTrack__VFTable {
    unsigned long long*(*dtor_0)(BSIMusicTrack_879dae29* , char);
    int (*DoUpdate_8)(void);
    int (*DoPlay_10)(void);
    int (*DoPause_18)(void);
    int (*DoFinish_20)(void);
    int (*GetDurationImpl_28)(void);
    int (*GetType_30)(void);
    char (*TestCanPlay_38)(void);
    long long (*GetMusicStatus_40)(BSIMusicTrack_879dae29* );
    void (*DoSetDuckingAttenuation_48)(void);
    void (*DoClearDucking_50)(void);
};
static_assert(sizeof(BSIMusicTrack__VFTable) == 88, "BSIMusicTrack__VFTable layout differs from the PDB");
