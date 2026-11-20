// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GASObjectInterface; size 0x18
#pragma once

struct GASObject;
struct GASObjectInterface_vtbl;
struct GASObjectInterface {
    GASObjectInterface_vtbl* __vftable;
    unsigned long long unk08;
    GASObject* __proto__;
};
static_assert(sizeof(GASObjectInterface) == 24, "GASObjectInterface layout differs from the PDB");
