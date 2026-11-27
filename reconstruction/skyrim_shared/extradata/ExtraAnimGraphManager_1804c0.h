// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraAnimGraphManager, BSAnimationGraphManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// ExtraAnimGraphManager::animGraphMgr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only
// ExtraAnimGraphManager::unk00, BSAnimationGraphManager::refCount: GUESS(low)
// ExtraAnimGraphManager::SetAnimGraphManager: GUESS(low)
#pragma once

class BSAnimationGraphManager
{
public:
    virtual ~BSAnimationGraphManager();

    long refCount;
};

class ExtraAnimGraphManager
{
public:
    void SetAnimGraphManager(BSAnimationGraphManager* const& a_in);  // compared: 0x1804c0

    char unk00[0x10];
    BSAnimationGraphManager* animGraphMgr;
};
