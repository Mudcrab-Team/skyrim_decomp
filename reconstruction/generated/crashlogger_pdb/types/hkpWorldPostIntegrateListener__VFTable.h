// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldPostIntegrateListener__VFTable; size 0x10
#pragma once

struct hkStepInfo_751f46fd;
struct hkpWorldPostIntegrateListener;
struct hkpWorld_938ebb10;
struct hkpWorldPostIntegrateListener__VFTable {
    void (*dtor_0)(hkpWorldPostIntegrateListener* );
    void (*postIntegrateCallback_8)(hkpWorldPostIntegrateListener* , hkpWorld_938ebb10* , hkStepInfo_751f46fd* );
};
static_assert(sizeof(hkpWorldPostIntegrateListener__VFTable) == 16, "hkpWorldPostIntegrateListener__VFTable layout differs from the PDB");
