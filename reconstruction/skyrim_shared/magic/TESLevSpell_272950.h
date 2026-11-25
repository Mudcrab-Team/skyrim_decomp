// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESLevSpell.cpp:132
// TESLevSpell, TESForm, SpellItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to the members the body uses
// TESLevSpell::GetLeveledSpell, TESLevSpell::CalculateCurrentForm, MagicSystem::School: SIBLING(fo4-private@1b765c70, author-permission)
// kNone: GUESS(low)
#pragma once

#include <cstdint>

namespace MagicSystem
{
    enum School
    {
        kNone = 0
    };
}

class TESForm
{
public:
    virtual ~TESForm();
};

class SpellItem : public TESForm
{
};

class TESLevSpell : public TESForm
{
public:
    SpellItem* GetLeveledSpell(MagicSystem::School aeSchool, short asLevel);
    void CalculateCurrentForm(MagicSystem::School aeSchool, unsigned short asLevel, TESForm*& apOutForm, unsigned short& asOutCount, bool abRecurse);
};
