// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldPostCollideListener__VFTable; size 0x10
#pragma once

struct hkStepInfo_751f46fd;
struct hkpWorldPostCollideListener;
struct hkpWorld_938ebb10;
struct hkpWorldPostCollideListener__VFTable {
    void (*dtor_0)(hkpWorldPostCollideListener* );
    void (*postCollideCallback_8)(hkpWorldPostCollideListener* , hkpWorld_938ebb10* , hkStepInfo_751f46fd* );
};
static_assert(sizeof(hkpWorldPostCollideListener__VFTable) == 16, "hkpWorldPostCollideListener__VFTable layout differs from the PDB");
