// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PersistentPassList; size 0x10
#pragma once

struct BSRenderPass_87210fc9;
struct PersistentPassList {
    BSRenderPass_87210fc9* head;
    BSRenderPass_87210fc9* tail;
};
static_assert(sizeof(PersistentPassList) == 16, "PersistentPassList layout differs from the PDB");
