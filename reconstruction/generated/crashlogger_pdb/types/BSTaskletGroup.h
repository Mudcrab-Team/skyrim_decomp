// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTaskletGroup; size 0x8
#pragma once

struct BSTaskletGroupData;
struct BSTaskletGroup {
    BSTaskletGroupData* data;
};
static_assert(sizeof(BSTaskletGroup) == 8, "BSTaskletGroup layout differs from the PDB");
