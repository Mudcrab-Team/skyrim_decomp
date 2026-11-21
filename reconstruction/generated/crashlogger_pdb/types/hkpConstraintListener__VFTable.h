// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintListener__VFTable; size 0x38
#pragma once

struct hkpConstraintBrokenEvent;
struct hkpConstraintInstance;
struct hkpConstraintListener;
struct hkpConstraintRepairedEvent;
struct hkpConstraintListener__VFTable {
    void (*dtor_0)(hkpConstraintListener* );
    void (*constraintAddedCallback_8)(hkpConstraintListener* , hkpConstraintInstance* );
    void (*constraintRemovedCallback_10)(hkpConstraintListener* , hkpConstraintInstance* );
    void (*constraintDeletedCallback_18)(hkpConstraintListener* , hkpConstraintInstance* );
    void (*constraintViolatedCallback_20)(hkpConstraintListener* , hkpConstraintInstance* );
    void (*constraintBreakingCallback_28)(hkpConstraintListener* , hkpConstraintBrokenEvent* );
    void (*constraintRepairedCallback_30)(hkpConstraintListener* , hkpConstraintRepairedEvent* );
};
static_assert(sizeof(hkpConstraintListener__VFTable) == 56, "hkpConstraintListener__VFTable layout differs from the PDB");
