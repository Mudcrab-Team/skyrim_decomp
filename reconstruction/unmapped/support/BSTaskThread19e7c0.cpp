// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x19e7c0 BSTaskThread19e7c0::StopAndWake
// Adapted bodies: none.
#include "BSTaskThread19e7c0.h"

// PDB: the CrashLogger PDB names this BSTaskThread::Func2_140150170 (the method name here is a guess); BSTaskThread19e7c0 is a stand-in for BSTaskThread with a partial layout.
// Marks the thread stopped, signals shutdown, and releases the wake semaphore.
void BSTaskThread19e7c0::StopAndWake()
{
    stopped60 = 1;
    StopThread();
    ReleaseSemaphore(semHandle58, 1, 0);
}
