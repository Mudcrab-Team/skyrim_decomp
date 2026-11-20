// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MobIterOperator_vtbl; size 0x10
#pragma once
struct MobIterOperator_vtbl {
    void (*_dtor_MobIterOperator)(void);
    void (*Operate)(char32_t* );
};
static_assert(sizeof(MobIterOperator_vtbl) == 16, "MobIterOperator_vtbl layout differs from the PDB");
