// CI hash: 0xec5ad0 ??1BSWin32TaskletGroupData@@UEAA@XZ
// CI hash: 0xec5c30 ??_GBSWin32TaskletGroupData@@UEAAPEAXI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSWin32TaskletGroupData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// 0xec5ad0 BSWin32TaskletGroupData::~BSWin32TaskletGroupData
// 0xec5c30 BSWin32TaskletGroupData::~BSWin32TaskletGroupData
#include "BSWin32TaskletGroupData_ec5ad0.h"

// The out-of-line constructor emits the vftable and the scalar deleting destructor.
BSWin32TaskletGroupData::BSWin32TaskletGroupData() = default;

// Wait for incomplete tasklets, then delete the critical section and close the semaphore handle.
BSWin32TaskletGroupData::~BSWin32TaskletGroupData()
{
    Finish();
    DeleteCriticalSection(&lock);
    CloseHandle(completionSemaphore);
}
