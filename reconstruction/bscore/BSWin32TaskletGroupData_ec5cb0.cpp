// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSWin32TaskletGroupData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSWin32TaskletGroupData::Cancel: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xec5cb0 BSWin32TaskletGroupData::Cancel
#include "BSWin32TaskletGroupData_ec5cb0.h"

// Mark the tasklet group cancelled while holding its critical section.
void BSWin32TaskletGroupData::Cancel()
{
    EnterCriticalSection(&lock);
    unk41 = false;
    cancelled = true;
    LeaveCriticalSection(&lock);
}
