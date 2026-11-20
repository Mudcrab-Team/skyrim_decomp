// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CCallbackBase; size 0x10
#pragma once

struct CCallbackBase_vtbl;
struct CCallbackBase {
    CCallbackBase_vtbl* __vftable;
    unsigned char callbackFlags;
    unsigned char pad09;
    unsigned short pad0A;
    int callback;
};
static_assert(sizeof(CCallbackBase) == 16, "CCallbackBase layout differs from the PDB");
