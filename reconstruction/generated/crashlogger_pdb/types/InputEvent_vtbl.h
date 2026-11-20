// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InputEvent_vtbl; size 0x18
#pragma once
struct InputEvent_vtbl {
    void (*_dtor_InputEvent)(void);
    bool (*HasIDCode)(void);
    char32_t*(*QUserEvent)(void);
};
static_assert(sizeof(InputEvent_vtbl) == 24, "InputEvent_vtbl layout differs from the PDB");
