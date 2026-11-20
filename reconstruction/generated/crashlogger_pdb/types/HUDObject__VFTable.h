// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HUDObject__VFTable; size 0x28
#pragma once

struct HUDObject_35c821a3;
struct HUDObject__VFTable {
    long long (*dtor_0)(HUDObject_35c821a3* , char);
    int (*Update_8)(void);
    char (*ProcessMessage_10)(void);
    long long (*RegisterHUDComponent_18)(HUDObject_35c821a3* , long long);
    void (*CleanUp_20)(void);
};
static_assert(sizeof(HUDObject__VFTable) == 40, "HUDObject__VFTable layout differs from the PDB");
