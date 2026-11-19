// Source exposure: mixed (names and declarations from community headers; base classes, sizes and the compared functions from the pinned image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSScene: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSScene::~BGSScene: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

// BGSScenePhase, BGSSceneAction: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the compared slots and the destruction path are needed
// BGSSceneAction::Slot01 to ::Slot0B: GUESS(low); placeholders up to the slot the compared Revert calls
// unkB0, unkB5, unkB6, unkB7, unkB9, unkBA, unkBB: GUESS(low); the bytes the compared Revert writes, named at their real offsets
// unkB1, unkB2, unkB3, unkB4, unkB8, unkBC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names as declared there, written by the compared Revert
// BGSScenePhase::unknown00, ::unknown08, ::unknown10: GUESS(low); named at their real offsets, the type is 0x18 bytes
class BGSScenePhase
{
public:
    ~BGSScenePhase();  // 00
    std::uint64_t unknown00;  // 00
    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
};
static_assert(sizeof(BGSScenePhase) == 0x18, "BGSScenePhase size");

class BGSSceneAction
{
public:
    virtual ~BGSSceneAction();  // 00
    virtual void Slot01();  // 01
    virtual void Slot02();  // 02
    virtual void Slot03();  // 03
    virtual void Slot04();  // 04
    virtual void Slot05();  // 05
    virtual void Slot06();  // 06
    virtual void Slot07();  // 07
    virtual void Slot08();  // 08
    virtual void Slot09();  // 09
    virtual void Slot0A();  // 0A
    virtual void Slot0B(BGSLoadFormBuffer* a_buf);  // 0B
};

// BSTArray, BSTArray::_data, ::_capacity, ::_unknown0C, ::_unknown14: STANDIN GUESS(low); the array layout is read from the target, the community type is declared differently
// BSTArray::_size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only
template <class T>
class BSTArray
{
public:
    T*            _data;      // 00
    std::uint32_t _capacity;  // 08
    std::uint32_t _unknown0C;     // 0C
    std::uint32_t _size;      // 10
    std::uint32_t _unknown14;     // 14
};

// TESCondition, TESCondition::head: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); target 0x4a6d90
class TESCondition
{
public:
    void* head;  // 00
};

class BGSScene : public TESForm
{
public:
    BGSScene();
    virtual ~BGSScene();  // compared: 0x3aa560 (scalar deleting destructor); declared only, rule 18

    void Revert(BGSLoadFormBuffer* a_buf) override;  // compared: 0x3a9170

    BSTArray<BGSScenePhase*>   phases;      // 20
    BSTArray<TESForm*>         actors;      // 38
    std::uint64_t              unknown50;  // 50
    std::uint64_t              unknown58;  // 58
    std::uint64_t              unknown60;  // 60
    std::uint64_t              unknown68;  // 68
    std::uint64_t              unknown70;  // 70
    std::uint64_t              unknown78;  // 78
    BSTArray<BGSSceneAction*>  actions;     // 80
    std::uint64_t              unknown98;   // 98
    std::uint64_t              unknownA0;   // A0
    TESCondition               conditions;  // A8
    std::uint8_t               unkB0;       // B0
    std::uint8_t               unkB1;       // B1
    std::uint8_t               unkB2;       // B2
    std::uint8_t               unkB3;       // B3
    std::uint8_t               unkB4;       // B4
    std::uint8_t               unkB5;       // B5
    std::uint8_t               unkB6;       // B6
    std::uint8_t               unkB7;       // B7
    std::uint8_t               unkB8;       // B8
    std::uint8_t               unkB9;       // B9
    std::uint8_t               unkBA;       // BA
    std::uint8_t               unkBB;       // BB
    std::uint32_t              unkBC;       // BC
    std::uint32_t              unkC0;       // C0
    std::uint32_t              unkC4;       // C4
};
static_assert(sizeof(BGSScene) == 0xC8, "BGSScene size");
