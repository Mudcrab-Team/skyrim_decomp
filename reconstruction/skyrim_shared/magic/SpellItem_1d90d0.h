// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SpellItem: GUESS(low); the class is the placeholder owner of a function taking a form
// GetMenuDisplayObject: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// BGSMenuDisplayObject, TESBoundObject, FormType, MagicEffect, Shout, formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESBoundObject::Function1e71b0: GUESS(low); a predicate on the form, bound by position
// menuDisplayA0, menuDisplay30: GUESS(low); the two display-object sub-objects the function can return
#pragma once

#include <cstdint>

enum class FormType : std::uint8_t
{
    MagicEffect = 0x12,
    Shout = 0x77
};

class BGSMenuDisplayObject
{
public:
    virtual ~BGSMenuDisplayObject();  // 00
    virtual void unk01();             // 01
    virtual void unk02();             // 02
    virtual void unk03();             // 03

    void* menuDispObject;  // 08
};

class TESBoundObject
{
public:
    bool Function1e71b0();  // bound: 0x1e71b0

    unsigned char pad00[0x1A];           // 00
    FormType formType;                   // 1A
    unsigned char pad1B[0x15];           // 1B
    BGSMenuDisplayObject menuDisplay30;  // 30
    unsigned char pad40[0x60];           // 40
    BGSMenuDisplayObject menuDisplayA0;  // A0
};

class SpellItem
{
public:
    static BGSMenuDisplayObject* GetMenuDisplayObject(TESBoundObject* a_form);  // compared: 0x1d90d0
};
