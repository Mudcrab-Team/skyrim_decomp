// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorFindAttackLocation.cpp:138
// CombatObject, spPath, spAimController, CheckLOSTimer, LoadGame, BGSLoadFormBuffer: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// AITimer: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// AITimer::LoadGame: SIBLING(fo4-private@1b765c70, author-permission) CRASHLOGGER_PDB(59818@2026.10.24)
// DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CombatBehaviorFindLateral8ab220, CombatObjectRef, Load, m_uiRefCount: GUESS(low)
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

struct AITimer
{
    float fStartTime;
    float fTargetTime;

    void LoadGame(BGSLoadFormBuffer* a_buffer);
};

// Reference-counting pointer to a combat object: retain the new object, release the old one, delete at zero.
struct CombatObjectRef
{
    CombatObject* m_pObject;

    CombatObjectRef& operator=(CombatObject* a_new)
    {
        CombatObject* old = m_pObject;
        if (old != a_new) {
            if (a_new) {
                _InterlockedIncrement(reinterpret_cast<volatile long*>(&a_new->m_uiRefCount));  // atomic: refcounts are shared across threads
            }
            m_pObject = a_new;
            if (old) {
                // atomic: refcounts are shared across threads
                std::uint32_t count = _InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount));
                if (count == 0) {
                    old->DeleteThis();
                }
            }
        }
        return *this;
    }
};

class CombatBehaviorFindLateral8ab220
{
public:
    void LoadGame(BGSLoadFormBuffer* a_buffer);  // compared: 0x8ab220

    CombatObjectRef spPath;
    CombatObjectRef spAimController;
    AITimer CheckLOSTimer;
};
