// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatAimControllerBase: EXE_RTTI
// CombatObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// CombatObject: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class CombatObject
{
public:
    CombatObject();
    virtual ~CombatObject();
};

class CombatAimControllerBase : public CombatObject
{
public:
    CombatAimControllerBase();
    ~CombatAimControllerBase() override {}

    char unk08[0x8];
};
static_assert(sizeof(CombatAimControllerBase) == 0x10, "CombatAimControllerBase size from the deleting destructor");
