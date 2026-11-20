// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IFunctionArguments_vtbl; size 0x10
#pragma once
struct IFunctionArguments_vtbl {
    void (*_dtor_IFunctionArguments)(void);
    bool (*operator_)(char32_t* );
};
static_assert(sizeof(IFunctionArguments_vtbl) == 16, "IFunctionArguments_vtbl layout differs from the PDB");
