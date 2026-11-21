// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCdPointCollector__VFTable; size 0x18
#pragma once

struct hkpCdPointCollector_f72767ea;
struct hkpCdPoint_ae8f4d2b;
struct hkpCdPointCollector__VFTable {
    void (*dtor_0)(hkpCdPointCollector_f72767ea* );
    void (*addCdPoint_8)(hkpCdPointCollector_f72767ea* , hkpCdPoint_ae8f4d2b* );
    void (*reset_10)(hkpCdPointCollector_f72767ea* );
};
static_assert(sizeof(hkpCdPointCollector__VFTable) == 24, "hkpCdPointCollector__VFTable layout differs from the PDB");
