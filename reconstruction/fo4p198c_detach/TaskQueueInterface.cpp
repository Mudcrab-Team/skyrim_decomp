// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// TaskQueueInterface::QueueNodeDetach: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// TaskQueueInterface::QueueActorKnockParalyze: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:213
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:432
// NiRefObject and BSHandleRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted reference-count declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x667ad0 TaskQueueInterface::QueueNodeDetach
// 0x668270 TaskQueueInterface::QueueActorKnockParalyze
#include "TaskQueueInterface.h"
#include <intrin.h>
void TaskQueueInterface::QueueNodeDetach(NiAVObject* object) {
    if (object) {
        BSPackedTask task;
        task.data[0].integer = 5;
        task.data[1].pointer = object;
        // Atomically retain the object while the queued task owns it.
        _InterlockedIncrement(&object->refCount);
        QueueIfActive(task);
    }
}
void TaskQueueInterface::QueueActorKnockParalyze(Actor* actor) {
    if (actor) {
        BSPackedTask task;
        task.data[0].integer = 13;
        task.data[1].pointer = actor;
        // Atomically retain the actor while the queued task owns it.
        _InterlockedIncrement(&actor->refCount);
        QueueIfActive(task);
    }
}
