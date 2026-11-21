// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PerkEntryVisitor_vtbl; size 0x8
#pragma once
struct PerkEntryVisitor_vtbl {
    void (*Visit)(char32_t* , char32_t* , char32_t* , unsigned char* );
};
static_assert(sizeof(PerkEntryVisitor_vtbl) == 8, "PerkEntryVisitor_vtbl layout differs from the PDB");
