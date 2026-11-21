// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IUnknownVtbl; size 0x18
#pragma once

struct GUID_86ee5d78;
struct IUnknown;
struct IUnknownVtbl {
    long (*QueryInterface)(IUnknown* , GUID_86ee5d78* , void** );
    unsigned long (*AddRef)(IUnknown* );
    unsigned long (*Release)(IUnknown* );
};
static_assert(sizeof(IUnknownVtbl) == 24, "IUnknownVtbl layout differs from the PDB");
