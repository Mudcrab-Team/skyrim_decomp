// Source exposure: mixed
// Origin: authorized sibling and community declarations
// TaskQueueInterface::QueueNodeAttach: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:199
// TaskQueueInterface, NiRefObject, NiAVObject, NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TaskQueueInterface.h and include/RE/N/NiRefObject.h
// names: GUESS(low); task layout and helper signature are provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); volatile long refCount; std::uint32_t pad0C; };
class NiObject : public NiRefObject {};
class NiObjectNET : public NiObject {};
class NiAVObject : public NiObjectNET {};
class NiNode : public NiAVObject {};
union PackedTaskData { std::uint32_t integer; void* pointer; bool boolean; };
struct BSPackedTask { PackedTaskData data[16]; };
class TaskQueueInterface {
public:
 void QueueIfActive(BSPackedTask&);
 void QueueNodeAttach(NiAVObject*, NiNode*, bool, bool);
};
