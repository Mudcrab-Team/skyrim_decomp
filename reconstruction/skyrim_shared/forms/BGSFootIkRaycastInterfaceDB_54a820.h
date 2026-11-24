// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Animation/BGSFootIkRaycastInterfaceDB.cpp:152
// BGSFootIkRaycastInterfaceDB, BGSFootIkRaycastInterfaceDB::KillSDM, BSIFootIkRaycastInterfaceDB: SIBLING(fo4-private@1b765c70, author-permission)
// BSTSingletonSDM: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a minimal single-parameter stand-in
// BSIFootIkRaycastInterfaceDB::pInstanceS, BSTSingletonSDM::KillSDM, BSTSingletonSDM::pInstance: GUESS(medium); names from the sibling body, declared outside the permitted folders
#pragma once

#include <cstdint>
#include <cstddef>

class BSIFootIkRaycastInterfaceDB
{
public:
    virtual ~BSIFootIkRaycastInterfaceDB();  // 00

    static BSIFootIkRaycastInterfaceDB* pInstanceS;
};

template <class T>
class BSTSingletonSDM
{
public:
    static void KillSDM()
    {
        if (pInstance)
        {
            pInstance->~T();
            pInstance = nullptr;
        }
    }

    static T* pInstance;
};

class BGSFootIkRaycastInterfaceDB : public BSIFootIkRaycastInterfaceDB, public BSTSingletonSDM<BGSFootIkRaycastInterfaceDB>
{
public:
    static void KillSDM();
};
