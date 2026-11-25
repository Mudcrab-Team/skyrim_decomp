// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatAreaStandard, CombatObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// CombatAreaRadius, CombatArea: EXE_RTTI
// CombatObject: STANDIN EXE_RTTI; only the members and destructors the function needs
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
};

class CombatAreaRadius : public CombatArea
{
public:
    CombatAreaRadius();
};

class CombatAreaStandard : public CombatAreaRadius
{
public:
    CombatAreaStandard();

    char unk08[0x48];
};
static_assert(sizeof(CombatAreaStandard) == 0x50, "CombatAreaStandard size from the deleting destructor");
