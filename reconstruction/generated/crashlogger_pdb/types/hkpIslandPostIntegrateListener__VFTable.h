// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpIslandPostIntegrateListener__VFTable; size 0x10
#pragma once

struct hkStepInfo_751f46fd;
struct hkpIslandPostIntegrateListener;
struct hkpSimulationIsland_f82b975f;
struct hkpIslandPostIntegrateListener__VFTable {
    void (*dtor_0)(hkpIslandPostIntegrateListener* );
    void (*postIntegrateCallback_8)(hkpIslandPostIntegrateListener* , hkpSimulationIsland_f82b975f* , hkStepInfo_751f46fd* );
};
static_assert(sizeof(hkpIslandPostIntegrateListener__VFTable) == 16, "hkpIslandPostIntegrateListener__VFTable layout differs from the PDB");
