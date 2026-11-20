// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IVMDebugInterface_vtbl; size 0x10
#pragma once
struct IVMDebugInterface_vtbl {
    void (*_dtor_IVMDebugInterface)(void);
    void (*DumpRunningStacksToLog)(void);
};
static_assert(sizeof(IVMDebugInterface_vtbl) == 16, "IVMDebugInterface_vtbl layout differs from the PDB");
