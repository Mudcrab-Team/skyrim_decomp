// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QueuedPromoteReferencesTask; size 0x50
#pragma once

struct BSTask__VFTable;
struct QueuedPromoteReferencesTask__VFTable;
struct QueuedPromoteReferencesTask {
    QueuedPromoteReferencesTask__VFTable* vftable_QueuedPromoteReferencesTask_0;
    BSTask__VFTable* vftable_BSTask_8;
    char _pad_10[64];
};
static_assert(sizeof(QueuedPromoteReferencesTask) == 80, "QueuedPromoteReferencesTask layout differs from the PDB");
