// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IUIMessageData; size 0x10
#pragma once

struct IUIMessageData_vtbl;
struct IUIMessageData {
    IUIMessageData_vtbl* __vftable;
    unsigned short unk08;
    unsigned short pad0A;
    unsigned int pad0C;
};
static_assert(sizeof(IUIMessageData) == 16, "IUIMessageData layout differs from the PDB");
