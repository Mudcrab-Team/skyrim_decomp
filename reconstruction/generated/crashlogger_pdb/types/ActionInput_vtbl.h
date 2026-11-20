// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActionInput_vtbl; size 0x20
#pragma once
struct ActionInput_vtbl {
    void (*_dtor_ActionInput)(void);
    char32_t*(*GetSourceActorState)(void);
    void (*Unk_02)(void);
    char32_t*(*GetSourceSequencer)(void);
};
static_assert(sizeof(ActionInput_vtbl) == 32, "ActionInput_vtbl layout differs from the PDB");
