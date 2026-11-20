// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldDeletionListener__VFTable; size 0x18
#pragma once

struct hkpWorldDeletionListener;
struct hkpWorld_938ebb10;
struct hkpWorldDeletionListener__VFTable {
    void (*dtor_0)(hkpWorldDeletionListener* );
    void (*worldDeletedCallback_8)(hkpWorldDeletionListener* , hkpWorld_938ebb10* );
    void (*worldRemoveAllCallback_10)(hkpWorldDeletionListener* , hkpWorld_938ebb10* );
};
static_assert(sizeof(hkpWorldDeletionListener__VFTable) == 24, "hkpWorldDeletionListener__VFTable layout differs from the PDB");
