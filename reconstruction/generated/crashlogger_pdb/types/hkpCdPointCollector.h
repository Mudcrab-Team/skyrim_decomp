// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCdPointCollector; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpCdPointCollector_vtbl;
struct hkpCdPointCollector {
    hkpCdPointCollector_vtbl* __vftable;
    float earlyOutDistance;
    unsigned int pad0C;
};
static_assert(sizeof(hkpCdPointCollector) == 16, "hkpCdPointCollector layout differs from the PDB");
