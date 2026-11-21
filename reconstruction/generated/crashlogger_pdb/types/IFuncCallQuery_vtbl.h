// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IFuncCallQuery_vtbl; size 0x10
#pragma once

#include "CallType.h"
struct IFuncCallQuery_vtbl {
    void (*_dtor_IFuncCallQuery)(void);
    bool (*GetFunctionCallInfo)(CallType* , char32_t* , char32_t* , char32_t* , char32_t* );
};
static_assert(sizeof(IFuncCallQuery_vtbl) == 16, "IFuncCallQuery_vtbl layout differs from the PDB");
