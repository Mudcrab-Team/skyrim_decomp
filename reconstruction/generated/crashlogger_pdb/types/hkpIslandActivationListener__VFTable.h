// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpIslandActivationListener__VFTable; size 0x18
#pragma once

struct hkpIslandActivationListener;
struct hkpSimulationIsland_f82b975f;
struct hkpIslandActivationListener__VFTable {
    void (*dtor_0)(hkpIslandActivationListener* );
    void (*islandActivatedCallback_8)(hkpIslandActivationListener* , hkpSimulationIsland_f82b975f* );
    void (*islandDeactivatedCallback_10)(hkpIslandActivationListener* , hkpSimulationIsland_f82b975f* );
};
static_assert(sizeof(hkpIslandActivationListener__VFTable) == 24, "hkpIslandActivationListener__VFTable layout differs from the PDB");
