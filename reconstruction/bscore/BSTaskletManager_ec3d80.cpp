// CI hash: 0xec3d80 ??_GBSTaskletManager@@UEAAPEAXI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTaskletManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// 0xec3d80 BSTaskletManager::~BSTaskletManager
#include "BSTaskletManager_ec3d80.h"

// Emit the class vftable and scalar deleting destructor.
BSTaskletManager::BSTaskletManager() = default;

// Close the instance semaphore handle on destruction.
BSTaskletManager::~BSTaskletManager()
{
    CloseHandle(instanceSemaphore);
}
