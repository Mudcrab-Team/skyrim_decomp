// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// TaskQueueInterface::QueueNodeDetach: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// TaskQueueInterface::QueueActorKnockParalyze: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:213
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:432
// NiRefObject and BSHandleRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted reference-count declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "TESForm.h"
#include <cstdint>
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); volatile long refCount; };
class NiAVObject : public NiRefObject {};
class BSHandleRefObject : public NiRefObject {};
class TESObjectREFR : public TESForm, public BSHandleRefObject {};
class Actor : public TESObjectREFR {};
union PackedTaskData { std::uint32_t integer; void* pointer; };
struct BSPackedTask { PackedTaskData data[16]; };
class TaskQueueInterface {
public:
    void QueueIfActive(BSPackedTask& task);
    void QueueNodeDetach(NiAVObject* object);
    void QueueActorKnockParalyze(Actor* actor);
};
