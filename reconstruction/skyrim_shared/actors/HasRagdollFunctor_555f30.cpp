// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x555f30 RagdollSystemUtils::HasRagdollFunctor::operator()
// CI hash: 0x555f30 ??RHasRagdollFunctor@RagdollSystemUtils@@QEAA?AW4ForEachResult@BSContainer@@AEBU?$BSTSmartPointer@VBShkbAnimationGraph@@UBSTSmartPointerIntrusiveRefCount@@@@@Z
// Adapted bodies: RagdollSystemUtils::HasRagdollFunctor::operator() from fo4-private@1b765c70 src/Shared/Animation/RagdollSystemUtils.cpp:5 (see the header)
#include "HasRagdollFunctor_555f30.h"

BSContainer::ForEachResult RagdollSystemUtils::HasRagdollFunctor::operator()(const BSTSmartPointer<BShkbAnimationGraph, BSTSmartPointerIntrusiveRefCount>& a_graph)
{
    if (a_graph.pPtr)
        bSuccess = bSuccess || a_graph.pPtr->HasRagdollImpl();
    return static_cast<BSContainer::ForEachResult>(!bSuccess);
}
