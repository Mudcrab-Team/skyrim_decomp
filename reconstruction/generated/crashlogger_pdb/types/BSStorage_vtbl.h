// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSStorage_vtbl; size 0x30
#pragma once

#include "ErrorCode.h"
#include "SeekMode.h"
struct BSStorage_vtbl {
    void (*_dtor_BSStorage)(void);
    unsigned long long (*GetSize)(void);
    void (*GetPosition)(char32_t* );
    ErrorCode (*Seek)(unsigned long long, SeekMode);
    ErrorCode (*Read)(unsigned long long, unsigned char* );
    ErrorCode (*Write)(unsigned long long, unsigned char* );
};
static_assert(sizeof(BSStorage_vtbl) == 48, "BSStorage_vtbl layout differs from the PDB");
