// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ForEachVisitor_vtbl; size 0x10
#pragma once
struct ForEachVisitor_vtbl {
    void (*_dtor_ForEachVisitor)(void);
    void (*Accept)(char32_t* );
};
static_assert(sizeof(ForEachVisitor_vtbl) == 16, "ForEachVisitor_vtbl layout differs from the PDB");
