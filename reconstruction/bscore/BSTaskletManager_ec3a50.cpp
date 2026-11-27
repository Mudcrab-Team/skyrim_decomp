// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTaskletManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSTaskletManager::AttachTask: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xec3a50 BSTaskletManager::AttachTask
#include "BSTaskletManager_ec3a50.h"

// Forward task attachment to the implementation slot when handles and manager state are valid.
bool BSTaskletManager::AttachTask(const TaskHandle& a_task, const GroupHandle& a_group)
{
    if (canCreateTaskGroup && a_task.ptr && a_group.data) {
        return DoAttachTask(a_task.ptr, a_group.data);
    }
    return false;
}
