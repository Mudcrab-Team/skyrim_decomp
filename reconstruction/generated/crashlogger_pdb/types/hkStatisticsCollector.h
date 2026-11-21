// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkStatisticsCollector; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkStatisticsCollector__VFTable;
struct hkVtableClassRegistry;
struct hkStatisticsCollector {
    hkStatisticsCollector__VFTable* vftable_hkStatisticsCollector_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    void* m_clientData_10;
    hkVtableClassRegistry* m_vtblRegistry_18;
    bool m_includeUnmanagedArrayMemory_20;
    char _pad_21[7];
};
static_assert(sizeof(hkStatisticsCollector) == 40, "hkStatisticsCollector layout differs from the PDB");
