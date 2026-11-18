// Source exposure: mixed
// Origin: authorized sibling and community declarations
// TaskQueueInterface::QueueNodeAttach: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:199
// TaskQueueInterface, NiRefObject, NiAVObject, NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TaskQueueInterface.h and include/RE/N/NiRefObject.h
// names: GUESS(low); task layout and helper signature are provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x667a80 TaskQueueInterface::QueueNodeAttach
#include "TaskQueueInterface.h"
#include <intrin.h>
void TaskQueueInterface::QueueNodeAttach(NiAVObject* child, NiNode* parent, bool firstAvailable, bool updateProperties) {
    BSPackedTask task;
    task.data[0].integer = 4;
    task.data[1].pointer = child;
    task.data[2].pointer = parent;
    task.data[4].boolean = updateProperties;
    task.data[3].boolean = firstAvailable;
    // Intrinsic preserves atomic reference ownership.
    _InterlockedIncrement(&child->refCount);
    // Intrinsic preserves atomic reference ownership.
    _InterlockedIncrement(&parent->refCount);
    QueueIfActive(task);
}
