// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StreamBase_vtbl; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "ErrorCode_092d7eaa.h"
struct Info;
struct StreamBase_vtbl_b596eab1 {
    void (*_dtor_StreamBase)(void);
    ErrorCode_092d7eaa (*DoOpen)(void);
    void (*DoClose)(void);
    unsigned long long (*DoGetKey)(void);
    ErrorCode_092d7eaa (*DoGetInfo)(Info* );
};
static_assert(sizeof(StreamBase_vtbl_b596eab1) == 40, "StreamBase_vtbl_b596eab1 layout differs from the PDB");
