// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactImpulseLimitBreachedListener__VFTable; size 0x10
#pragma once

struct hkpContactImpulseLimitBreachedListener;
struct hkpContactImpulseLimitBreachedListenerInfo;
struct hkpContactImpulseLimitBreachedListener__VFTable {
    void (*dtor_0)(hkpContactImpulseLimitBreachedListener* );
    void (*contactImpulseLimitBreachedCallback_8)(hkpContactImpulseLimitBreachedListener* , hkpContactImpulseLimitBreachedListenerInfo* , int);
};
static_assert(sizeof(hkpContactImpulseLimitBreachedListener__VFTable) == 16, "hkpContactImpulseLimitBreachedListener__VFTable layout differs from the PDB");
