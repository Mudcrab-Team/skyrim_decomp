// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMovementControllerRegisterInterface_vtbl; size 0x28
#pragma once
struct IMovementControllerRegisterInterface_vtbl {
    void (*_dtor_IMovementControllerRegisterInterface)(void);
    bool (*RegisterInterface)(char32_t* , char32_t* );
    char32_t*(*GetInterface1)(char32_t* );
    char32_t*(*GetInterface2)(char32_t* );
    void (*Unk_04)(void);
};
static_assert(sizeof(IMovementControllerRegisterInterface_vtbl) == 40, "IMovementControllerRegisterInterface_vtbl layout differs from the PDB");
