// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpIslandPostCollideListener__VFTable; size 0x10
#pragma once

struct hkStepInfo_751f46fd;
struct hkpIslandPostCollideListener;
struct hkpSimulationIsland_f82b975f;
struct hkpIslandPostCollideListener__VFTable {
    void (*dtor_0)(hkpIslandPostCollideListener* );
    void (*postCollideCallback_8)(hkpIslandPostCollideListener* , hkpSimulationIsland_f82b975f* , hkStepInfo_751f46fd* );
};
static_assert(sizeof(hkpIslandPostCollideListener__VFTable) == 16, "hkpIslandPostCollideListener__VFTable layout differs from the PDB");
