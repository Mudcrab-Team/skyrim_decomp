// Exposure detail: (local target analysis and community declarations).
// Source exposure: mixed
// Code origin: original reconstruction from target observations and attributed community material.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IAnimationGraphManagerHolder, GetAnimationGraphManagerImpl, NotifyAnimationGraph, BSAnimationGraphManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations and name hints.
// HasAnimationGraphManager: SIBLING(fo4-private@1b765c70, author-permission); name hint only.
// ManagerReference, DeleteThis, refCount: GUESS(low); query and ownership inferred from local target.
// 0x552eb0 IAnimationGraphManagerHolder::HasAnimationGraphManager

#pragma once
#include <cstdint>
#include <intrin.h>

class BSAnimationGraphManager
{
public:
    virtual void DeleteThis();
    long refCount;  // 08
};

class IAnimationGraphManagerHolder
{
public:
    virtual ~IAnimationGraphManagerHolder();
    virtual bool NotifyAnimationGraph(const void* eventName);
    virtual bool GetAnimationGraphManagerImpl(BSAnimationGraphManager*& out) const;
    bool HasAnimationGraphManager() const;
};
