// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSISoundDescriptor_vtbl; size 0x18
#pragma once
struct BSISoundDescriptor_vtbl {
    void (*_dtor_BSISoundDescriptor)(void);
    bool (*DoResolve)(char32_t* );
    void (*Unk_02)(void);
};
static_assert(sizeof(BSISoundDescriptor_vtbl) == 24, "BSISoundDescriptor_vtbl layout differs from the PDB");
