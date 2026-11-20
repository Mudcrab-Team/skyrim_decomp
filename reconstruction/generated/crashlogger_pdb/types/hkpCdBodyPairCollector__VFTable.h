// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCdBodyPairCollector__VFTable; size 0x18
#pragma once

struct hkpCdBodyPairCollector;
struct hkpCdBody_cce531ab;
struct hkpCdBodyPairCollector__VFTable {
    void (*dtor_0)(hkpCdBodyPairCollector* );
    void (*addCdBodyPair_8)(hkpCdBodyPairCollector* , hkpCdBody_cce531ab* , hkpCdBody_cce531ab* );
    void (*reset_10)(hkpCdBodyPairCollector* );
};
static_assert(sizeof(hkpCdBodyPairCollector__VFTable) == 24, "hkpCdBodyPairCollector__VFTable layout differs from the PDB");
