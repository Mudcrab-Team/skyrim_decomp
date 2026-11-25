// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Animation/RagdollSystemUtils.cpp:5
// BSContainer::ForEachResult, BSTSmartPointer, BSTSmartPointerIntrusiveRefCount: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RagdollSystemUtils, RagdollSystemUtils::HasRagdollFunctor, RagdollSystemUtils::HasRagdollFunctor::operator(), RagdollSystemUtils::HasRagdollFunctor::bSuccess, BShkbAnimationGraph, BShkbAnimationGraph::HasRagdollImpl: GUESS(medium); names from the sibling body, declared outside the permitted folders
// unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

namespace BSContainer
{
    enum class ForEachResult
    {
        kStop = 0,
        kContinue = 1
    };
}

struct BSTSmartPointerIntrusiveRefCount
{
};

template <class T, class RefCount = BSTSmartPointerIntrusiveRefCount>
struct BSTSmartPointer
{
    T* pPtr;  // 00
};

class BShkbAnimationGraph
{
public:
    virtual ~BShkbAnimationGraph();  // 00
    virtual bool HasRagdollImpl();   // 01
};

namespace RagdollSystemUtils
{
    struct HasRagdollFunctor
    {
        BSContainer::ForEachResult operator()(const BSTSmartPointer<BShkbAnimationGraph, BSTSmartPointerIntrusiveRefCount>& a_graph);

        bool bSuccess;  // 00
    };
}
