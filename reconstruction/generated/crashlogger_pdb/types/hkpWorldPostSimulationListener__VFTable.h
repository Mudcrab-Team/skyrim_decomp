// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldPostSimulationListener__VFTable; size 0x18
#pragma once

struct hkpEntity_b3bc9432;
struct hkpWorldPostSimulationListener_ae25f20e;
struct hkpWorld_938ebb10;
struct hkpWorldPostSimulationListener__VFTable {
    void (*dtor_0)(hkpWorldPostSimulationListener_ae25f20e* );
    void (*postSimulationCallback_8)(hkpWorldPostSimulationListener_ae25f20e* , hkpWorld_938ebb10* );
    void (*inactiveEntityMovedCallback_10)(hkpWorldPostSimulationListener_ae25f20e* , hkpEntity_b3bc9432* );
};
static_assert(sizeof(hkpWorldPostSimulationListener__VFTable) == 24, "hkpWorldPostSimulationListener__VFTable layout differs from the PDB");
