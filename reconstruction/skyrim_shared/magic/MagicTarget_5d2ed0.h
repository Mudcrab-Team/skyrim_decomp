// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTarget, VisitEffects, ForEachActiveEffectVisitor, Accept, GetActiveEffectList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ForEachActiveEffect: CRASHLOGGER_PDB(59818@2026.10.24); the unit uses the community name VisitEffects
// ForEachResult, kStop, kContinue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffect, BSSimpleList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// item, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

class ActiveEffect;

namespace BSContainer
{
    enum class ForEachResult
    {
        kStop = 0,
        kContinue = 1
    };
}

template <class T>
struct BSSimpleList
{
    T item;                 // 00
    BSSimpleList* next;     // 08
};

class MagicTarget
{
public:
    class ForEachActiveEffectVisitor
    {
    public:
        virtual ~ForEachActiveEffectVisitor() {}                                    // 00
        virtual BSContainer::ForEachResult Accept(ActiveEffect* a_effect) = 0;       // 01
    };

    virtual ~MagicTarget();                                    // 00
    virtual void unk01();                                      // 01
    virtual void unk02();                                      // 02
    virtual void unk03();                                      // 03
    virtual void unk04();                                      // 04
    virtual void unk05();                                      // 05
    virtual void unk06();                                      // 06
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();  // 07

    void VisitEffects(ForEachActiveEffectVisitor& visitor);  // compared: 0x5d2ed0
};
