// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetGraphVariableCacheSize: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/Animation/IAnimationGraphManagerHolder.cpp:225; signature hint only; target reads a global.
// Semantic names and types: GUESS(low); except where separately attributed.
// IAnimationGraphManagerHolder, IAnimationGraphManagerHolder::~IAnimationGraphManagerHolder: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the interface's other virtual slots are not declared
#pragma once
extern unsigned int graphVariableCacheSize;
class IAnimationGraphManagerHolder
{
public:
    IAnimationGraphManagerHolder();
    virtual ~IAnimationGraphManagerHolder();  // 00
    unsigned int GetGraphVariableCacheSize() const;
};
