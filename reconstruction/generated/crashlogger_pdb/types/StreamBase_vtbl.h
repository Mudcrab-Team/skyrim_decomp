// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StreamBase_vtbl; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ErrorCode.h"
struct StreamBase_vtbl {
    void (*_dtor_StreamBase)(void);
    ErrorCode (*DoOpen)(void);
    void (*DoClose)(void);
    unsigned long long (*DoGetKey)(void);
    ErrorCode (*DoGetInfo)(char32_t* );
};
static_assert(sizeof(StreamBase_vtbl) == 40, "StreamBase_vtbl layout differs from the PDB");
