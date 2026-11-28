// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj255680::FindByEditorID, treated as adapted: shaped like TESRegionList::Find in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist_h_unit.cpp:102
// SPDX-License-Identifier: CC0-1.0
// Form255680, Node255680, ListOwner255680, Obj255680, GetEditorID, FindByEditorID, item, next, head: GUESS(low)
#pragma once

#include <cstdint>

struct Form255680
{
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03(); virtual void V04();
    virtual void V05(); virtual void V06(); virtual void V07(); virtual void V08(); virtual void V09();
    virtual void V10(); virtual void V11(); virtual void V12(); virtual void V13(); virtual void V14();
    virtual void V15(); virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23(); virtual void V24();
    virtual void V25(); virtual void V26(); virtual void V27(); virtual void V28(); virtual void V29();
    virtual void V30(); virtual void V31(); virtual void V32(); virtual void V33(); virtual void V34();
    virtual void V35(); virtual void V36(); virtual void V37(); virtual void V38(); virtual void V39();
    virtual void V40(); virtual void V41(); virtual void V42(); virtual void V43(); virtual void V44();
    virtual void V45(); virtual void V46(); virtual void V47(); virtual void V48(); virtual void V49();
    virtual const char* GetEditorID();  // 190
};

struct Node255680
{
    Form255680* item;  // 00
    Node255680* next;  // 08
};

struct ListOwner255680
{
    std::uint64_t unk00;  // 00
    Node255680 head;      // 08
};

extern "C" __declspec(dllimport) int __cdecl _stricmp(const char* lhs, const char* rhs);

class Obj255680
{
public:
    static Form255680* FindByEditorID(ListOwner255680* owner, const char* editorID);
};
