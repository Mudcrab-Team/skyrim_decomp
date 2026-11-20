// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCdPointCollector_vtbl; size 0x18
#pragma once
struct hkpCdPointCollector_vtbl {
    void (*_dtor_hkpCdPointCollector)(void);
    void (*AddCdPoint)(char32_t* );
    void (*Reset)(void);
};
static_assert(sizeof(hkpCdPointCollector_vtbl) == 24, "hkpCdPointCollector_vtbl layout differs from the PDB");
