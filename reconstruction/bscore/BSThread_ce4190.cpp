// CI hash: 0xce4190 ?Functionce4190@BSThread@@QEAAXXZ
// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original polymorphic reconstruction with provisional method signatures.
// SPDX-License-Identifier: CC0-1.0
// BSThread: STANDIN EXE_RTTI
// BSThread::~BSThread, BSThread::Unk_01, BSThread::Unk_02, BSThread::Functionce4190, BSThread::criticalSection, BSThread::thread, BSThread::threadID, BSThread::running: GUESS(low)
// 0xce4190 BSThread::Functionce4190
#include "BSThread_ce4190.h"

// Forward to the virtual operation.
void BSThread::Functionce4190()
{
    if (thread) {
        running = 0;
        EnterCriticalSection(&criticalSection);
        if (GetCurrentThreadId() != threadID) {
            while (WaitForSingleObject(thread, 10) == WAIT_TIMEOUT) Unk_02();
        }
        CloseHandle(thread);
        thread = nullptr;
        LeaveCriticalSection(&criticalSection);
    }
}
