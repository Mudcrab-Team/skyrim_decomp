// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAnimationGraphChannel_vtbl; size 0x18
#pragma once
struct BSAnimationGraphChannel_vtbl {
    void (*_dtor_BSAnimationGraphChannel)(void);
    void (*PollChannelUpdateImpl)(bool);
    void (*ResetImpl)(void);
};
static_assert(sizeof(BSAnimationGraphChannel_vtbl) == 24, "BSAnimationGraphChannel_vtbl layout differs from the PDB");
