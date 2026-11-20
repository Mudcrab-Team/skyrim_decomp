// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIMusicTrack_vtbl; size 0x58
#pragma once

#include "MUSIC_STATUS.h"
#include "hkpPhantomType.h"
struct BSIMusicTrack_vtbl {
    void (*_dtor_BSIMusicTrack)(void);
    void (*DoUpdate)(void);
    void (*DoPlay)(void);
    void (*DoPause)(void);
    void (*DoFinish)(bool);
    float (*GetDurationImpl)(void);
    hkpPhantomType (*GetType)(void);
    bool (*TestCanPlay)(void);
    MUSIC_STATUS (*GetMusicStatus)(void);
    void (*DoSetDuckingAttenuation)(unsigned short);
    void (*DoClearDucking)(void);
};
static_assert(sizeof(BSIMusicTrack_vtbl) == 88, "BSIMusicTrack_vtbl layout differs from the PDB");
