// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpPhantomListener__VFTable; size 0x28
#pragma once

struct hkpPhantom;
struct hkpPhantomListener;
struct hkpPhantomListener__VFTable {
    void (*dtor_0)(hkpPhantomListener* );
    void (*phantomAddedCallback_8)(hkpPhantomListener* , hkpPhantom* );
    void (*phantomRemovedCallback_10)(hkpPhantomListener* , hkpPhantom* );
    void (*phantomShapeSetCallback_18)(hkpPhantomListener* , hkpPhantom* );
    void (*phantomDeletedCallback_20)(hkpPhantomListener* , hkpPhantom* );
};
static_assert(sizeof(hkpPhantomListener__VFTable) == 40, "hkpPhantomListener__VFTable layout differs from the PDB");
