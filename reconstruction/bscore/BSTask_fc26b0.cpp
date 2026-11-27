// CI hash: 0xfc26b0 ??1BSTask@@UEAA@XZ
// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original polymorphic reconstruction with provisional method signatures.
// SPDX-License-Identifier: CC0-1.0
// BSTask: STANDIN EXE_RTTI
// BSTask::~BSTask, BSTask::Unk_01, BSTask::Unk_02, BSTask::Unk_03, BSTask::Unk_04, BSTask::~BSTask: GUESS(low)
// 0xfc26b0 BSTask::~BSTask
#include "BSTask_fc26b0.h"

// Release the owned resource.
BSTask::~BSTask()
{
    // Atomic decrement releases this task from the shared live count.
    _InterlockedDecrement(&gTaskCount);
}
