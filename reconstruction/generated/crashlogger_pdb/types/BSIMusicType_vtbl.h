// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIMusicType_vtbl; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct BSIMusicType_vtbl {
    void (*DoUpdate)(void);
    void (*DoPlay)(void);
    void (*DoPause)(void);
    void (*DoFinish)(bool);
    void (*DoApplyDuckingAttenuation)(unsigned short);
    void (*DoClearDucking)(void);
    void (*DoPrepare)(void);
    void (*_dtor_BSIMusicType)(void);
};
static_assert(sizeof(BSIMusicType_vtbl) == 64, "BSIMusicType_vtbl layout differs from the PDB");
