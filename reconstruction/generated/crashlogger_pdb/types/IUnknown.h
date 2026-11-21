// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IUnknown; size 0x8
#pragma once

struct IUnknownVtbl;
struct IUnknown {
    IUnknownVtbl* lpVtbl;
};
static_assert(sizeof(IUnknown) == 8, "IUnknown layout differs from the PDB");
