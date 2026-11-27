// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorCloseMovement.cpp:312
// CombatObject: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CombatBehavior8970d0, LoadGame, spPath, Load, m_uiRefCount, Assign: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class BGSLoadFormBuffer;

class CombatObject
{
public:
    virtual ~CombatObject();
    virtual void DeleteThis();
    static CombatObject* Load(BGSLoadFormBuffer* a_buffer);

    std::uint32_t m_uiRefCount;
};

class CombatBehavior8970d0
{
public:
    void LoadGame(BGSLoadFormBuffer* a_buffer);  // compared: 0x8970d0

    // Smart-pointer assignment: retain the new object, release the old one, delete at zero.
    void Assign(CombatObject* a_new)
    {
        CombatObject* old = spPath;
        if (old != a_new) {
            if (a_new) {
                _InterlockedIncrement(reinterpret_cast<volatile long*>(&a_new->m_uiRefCount));  // atomic: refcounts are shared across threads
            }
            spPath = a_new;
            if (old && !_InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount))) {  // atomic: refcounts are shared across threads
                old->DeleteThis();
            }
        }
    }

    CombatObject* spPath;
};
