// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Variable; size 0x10
#pragma once

#include "TypeInfo.h"
#include "Value.h"
struct Variable {
    TypeInfo varType;
    Value value;
};
static_assert(sizeof(Variable) == 16, "Variable layout differs from the PDB");
