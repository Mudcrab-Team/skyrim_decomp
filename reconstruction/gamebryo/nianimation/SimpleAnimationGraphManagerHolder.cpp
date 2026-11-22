// Source exposure: mixed (pinned image listing, sibling hint, community declarations).
// Code origin: existing sibling-adapted methods plus original reconstruction of Function5564e0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Animation/SimpleAnimationGraphManagerHolder.cpp:66
// Sibling source: fo4-private@1b765c70 src/Shared/Animation/SimpleAnimationGraphManagerHolder.cpp:73
// Adapted bodies: GetAnimationGraphManagerImpl and SetAnimationGraphManagerImpl from fo4-private@1b765c70; Function5564e0 original.
// 0x556670 SimpleAnimationGraphManagerHolder::SetAnimationGraphManagerImpl
// 0x556610 SimpleAnimationGraphManagerHolder::GetAnimationGraphManagerImpl
// 0x5564e0 SimpleAnimationGraphManagerHolder::Function5564e0
#include "SimpleAnimationGraphManagerHolder.h"

bool SimpleAnimationGraphManagerHolder::GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& out) const { out=animationGraphManager; return out.ptr != nullptr; }
bool SimpleAnimationGraphManagerHolder::SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& in) { animationGraphManager=in; return true; }
bool SimpleAnimationGraphManagerHolder::Function5564e0() const { return !loadingTask || loadingTask->state2C8 == 3u; }
