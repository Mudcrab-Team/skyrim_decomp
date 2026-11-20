// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExecuteTagList; size 0x10
#pragma once

struct GASExecuteTag;
struct ExecuteTagList {
    GASExecuteTag** data;
    unsigned int size;
    unsigned char undefined_c[4];
};
static_assert(sizeof(ExecuteTagList) == 16, "ExecuteTagList layout differs from the PDB");
