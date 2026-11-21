// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldPostSimulationListener_vtbl; size 0x18
#pragma once
struct hkpWorldPostSimulationListener_vtbl {
    void (*_dtor_hkpWorldPostSimulationListener)(void);
    void (*PostSimulationCallback)(char32_t* );
    void (*InactiveEntityMovedCallback)(char32_t* );
};
static_assert(sizeof(hkpWorldPostSimulationListener_vtbl) == 24, "hkpWorldPostSimulationListener_vtbl layout differs from the PDB");
