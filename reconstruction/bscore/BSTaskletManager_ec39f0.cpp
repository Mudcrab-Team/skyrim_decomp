// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTaskletManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSTaskletManager::CreateTaskGroup: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xec39f0 BSTaskletManager::CreateTaskGroup
#include "BSTaskletManager_ec39f0.h"

// Create a task group through the virtual slot when group creation is enabled.
bool BSTaskletManager::CreateTaskGroup(void** a_outGroup)
{
    if (canCreateTaskGroup) {
        void* group;
        const bool ok = DoCreateTaskGroup(&group);
        *a_outGroup = group;
        return ok;
    }
    *a_outGroup = nullptr;
    return false;
}
