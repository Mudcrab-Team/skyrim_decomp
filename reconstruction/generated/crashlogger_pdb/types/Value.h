// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Value; size 0x8
#pragma once
struct Value {
    float f;
    unsigned char undefined_4[4];
};
static_assert(sizeof(Value) == 8, "Value layout differs from the PDB");
