// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CCallbackBase_vtbl; size 0x18
#pragma once
struct CCallbackBase_vtbl {
    void (*Run)(unsigned char);
    void (*Run_2)(unsigned char);
    int (*GetCallbackSizeBytes)(void);
};
static_assert(sizeof(CCallbackBase_vtbl) == 24, "CCallbackBase_vtbl layout differs from the PDB");
