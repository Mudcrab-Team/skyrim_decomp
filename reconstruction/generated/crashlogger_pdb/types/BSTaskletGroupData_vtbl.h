// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTaskletGroupData_vtbl; size 0x28
#pragma once
struct BSTaskletGroupData_vtbl {
    void (*_dtor_BSTaskletGroupData)(void);
    void (*WaitForCompletion)(bool);
    void (*Cancel)(void);
    void (*WaitForCompletionTimeout)(float);
    void (*Unk_04)(void);
};
static_assert(sizeof(BSTaskletGroupData_vtbl) == 40, "BSTaskletGroupData_vtbl layout differs from the PDB");
