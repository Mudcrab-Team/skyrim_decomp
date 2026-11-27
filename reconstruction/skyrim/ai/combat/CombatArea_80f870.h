// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatArea: EXE_RTTI
// CombatObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// CombatObject: STANDIN EXE_RTTI; only its out-of-line destructor is declared
#pragma once

class CombatObject
{
public:
    CombatObject();
    virtual ~CombatObject();
};

class CombatArea : public CombatObject
{
public:
    CombatArea();
    ~CombatArea() override {}

    char unk08[0x28];
};
static_assert(sizeof(CombatArea) == 0x30, "CombatArea size from the deleting destructor");
