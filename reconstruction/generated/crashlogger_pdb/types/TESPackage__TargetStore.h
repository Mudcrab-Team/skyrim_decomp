// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackage__TargetStore; size 0x8
#pragma once

struct TESForm_4074aa87;
union TESPackage__TargetStore {
    unsigned int ObjectRefHandle_0;
    TESForm_4074aa87* Form_0;
    int ObjectType_0;
    unsigned int AliasId_0;
    int InterruptTarget_0;
};
static_assert(sizeof(TESPackage__TargetStore) == 8, "TESPackage__TargetStore layout differs from the PDB");
