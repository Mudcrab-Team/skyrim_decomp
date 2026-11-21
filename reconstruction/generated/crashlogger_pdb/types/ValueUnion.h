// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ValueUnion; size 0x8
#pragma once
struct ValueUnion {
    void* obj;
};
static_assert(sizeof(ValueUnion) == 8, "ValueUnion layout differs from the PDB");
