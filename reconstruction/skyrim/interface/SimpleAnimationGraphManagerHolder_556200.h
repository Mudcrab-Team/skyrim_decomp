// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; handwritten from pinned-image observations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SimpleAnimationGraphManagerHolder, IAnimationGraphManagerHolder: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// animationGraphManager, loadingTask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IAnimationGraphManagerHolder: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; only constructor and polymorphic prefix declared
#pragma once
#include <cstddef>

class IAnimationGraphManagerHolder
{
public:
    IAnimationGraphManagerHolder();
    virtual ~IAnimationGraphManagerHolder();
};

class SimpleAnimationGraphManagerHolder : public IAnimationGraphManagerHolder
{
public:
    SimpleAnimationGraphManagerHolder();
    ~SimpleAnimationGraphManagerHolder() override;
    // Pointer storage represents the smart-pointer members in this constructor-only declaration.
    void* animationGraphManager;
    void* loadingTask;
};
static_assert(sizeof(SimpleAnimationGraphManagerHolder) == 24, "holder storage");
static_assert(offsetof(SimpleAnimationGraphManagerHolder, animationGraphManager) == 8, "manager offset");
static_assert(offsetof(SimpleAnimationGraphManagerHolder, loadingTask) == 16, "task offset");
