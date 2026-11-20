// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpActionListener__VFTable; size 0x18
#pragma once

struct hkpAction;
struct hkpActionListener;
struct hkpActionListener__VFTable {
    void (*dtor_0)(hkpActionListener* );
    void (*actionAddedCallback_8)(hkpActionListener* , hkpAction* );
    void (*actionRemovedCallback_10)(hkpActionListener* , hkpAction* );
};
static_assert(sizeof(hkpActionListener__VFTable) == 24, "hkpActionListener__VFTable layout differs from the PDB");
