// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ErrorLogger_vtbl; size 0x18
#pragma once

#include "Severity.h"
struct ErrorLogger_vtbl {
    void (*_dtor_ErrorLogger)(void);
    void (*PostErrorImpl)(unsigned char* , Severity);
    void (*ResetImpl)(void);
};
static_assert(sizeof(ErrorLogger_vtbl) == 24, "ErrorLogger_vtbl layout differs from the PDB");
