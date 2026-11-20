// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QueuedPromoteLocationReferencesTask; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSTask__VFTable;
struct QueuedPromoteLocationReferencesTask__VFTable;
struct QueuedPromoteLocationReferencesTask {
    QueuedPromoteLocationReferencesTask__VFTable* vftable_QueuedPromoteLocationReferencesTask_0;
    BSTask__VFTable* vftable_BSTask_8;
    char _pad_10[72];
};
static_assert(sizeof(QueuedPromoteLocationReferencesTask) == 88, "QueuedPromoteLocationReferencesTask layout differs from the PDB");
