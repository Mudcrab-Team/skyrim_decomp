// CI hash: 0xce3fe0 ??1BSThread@@UEAA@XZ
// CI hash: 0xce42a0 ??_GBSThread@@UEAAPEAXI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSThread: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// 0xce3fe0 BSThread::~BSThread
// 0xce42a0 BSThread::~BSThread
#include "BSThread_ce3fe0.h"

// The out-of-line constructor emits the vftable and the scalar deleting destructor.
BSThread::BSThread() = default;

// Wait for the worker thread handle if active, close it, and delete the critical section.
BSThread::~BSThread()
{
    Shutdown();
    DeleteCriticalSection(&lock);
}
