// Source exposure: mixed
// Code origin: original declaration view from the pinned image and labelled community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor, Actor::currentProcess, Actor::Get3D1, Actor::Get3D2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::SetAlpha: CRASHLOGGER_PDB(59818@2026.10.24) COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess, NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject::fadeAmount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::GetProcessLevel, AIProcess::SetMaxAlpha: SIBLING(fo4-private@1b765c70, author-permission)
// playerSingleton, unkPadding08, unkPadding00: GUESS(low)
// unkSlot00, unkSlot01, unkSlot02, unkSlot03, unkSlot04, unkSlot05, unkSlot06, unkSlot07, unkSlot08, unkSlot09, unkSlot0A, unkSlot0B, unkSlot0C, unkSlot0D, unkSlot0E, unkSlot0F, unkSlot10, unkSlot11, unkSlot12, unkSlot13, unkSlot14, unkSlot15, unkSlot16, unkSlot17, unkSlot18, unkSlot19, unkSlot1A, unkSlot1B, unkSlot1C, unkSlot1D, unkSlot1E, unkSlot1F, unkSlot20, unkSlot21, unkSlot22, unkSlot23, unkSlot24, unkSlot25, unkSlot26, unkSlot27, unkSlot28, unkSlot29, unkSlot2A, unkSlot2B, unkSlot2C, unkSlot2D, unkSlot2E, unkSlot2F, unkSlot30, unkSlot31, unkSlot32, unkSlot33, unkSlot34, unkSlot35, unkSlot36, unkSlot37, unkSlot38, unkSlot39, unkSlot3A, unkSlot3B, unkSlot3C, unkSlot3D, unkSlot3E, unkSlot3F, unkSlot40, unkSlot41, unkSlot42, unkSlot43, unkSlot44, unkSlot45, unkSlot46, unkSlot47, unkSlot48, unkSlot49, unkSlot4A, unkSlot4B, unkSlot4C, unkSlot4D, unkSlot4E, unkSlot4F, unkSlot50, unkSlot51, unkSlot52, unkSlot53, unkSlot54, unkSlot55, unkSlot56, unkSlot57, unkSlot58, unkSlot59, unkSlot5A, unkSlot5B, unkSlot5C, unkSlot5D, unkSlot5E, unkSlot5F, unkSlot60, unkSlot61, unkSlot62, unkSlot63, unkSlot64, unkSlot65, unkSlot66, unkSlot67, unkSlot68, unkSlot69, unkSlot6A, unkSlot6B, unkSlot6C, unkSlot6D, unkSlot6E: GUESS(low)
#pragma once

#include <cstddef>

class AIProcess
{
public:
    void SetMaxAlpha(float a_alpha);
};

class NiAVObject
{
public:
    unsigned char unkPadding00[0x100];
    float fadeAmount;
};

class Actor
{
public:
    virtual void unkSlot00();
    virtual void unkSlot01();
    virtual void unkSlot02();
    virtual void unkSlot03();
    virtual void unkSlot04();
    virtual void unkSlot05();
    virtual void unkSlot06();
    virtual void unkSlot07();
    virtual void unkSlot08();
    virtual void unkSlot09();
    virtual void unkSlot0A();
    virtual void unkSlot0B();
    virtual void unkSlot0C();
    virtual void unkSlot0D();
    virtual void unkSlot0E();
    virtual void unkSlot0F();
    virtual void unkSlot10();
    virtual void unkSlot11();
    virtual void unkSlot12();
    virtual void unkSlot13();
    virtual void unkSlot14();
    virtual void unkSlot15();
    virtual void unkSlot16();
    virtual void unkSlot17();
    virtual void unkSlot18();
    virtual void unkSlot19();
    virtual void unkSlot1A();
    virtual void unkSlot1B();
    virtual void unkSlot1C();
    virtual void unkSlot1D();
    virtual void unkSlot1E();
    virtual void unkSlot1F();
    virtual void unkSlot20();
    virtual void unkSlot21();
    virtual void unkSlot22();
    virtual void unkSlot23();
    virtual void unkSlot24();
    virtual void unkSlot25();
    virtual void unkSlot26();
    virtual void unkSlot27();
    virtual void unkSlot28();
    virtual void unkSlot29();
    virtual void unkSlot2A();
    virtual void unkSlot2B();
    virtual void unkSlot2C();
    virtual void unkSlot2D();
    virtual void unkSlot2E();
    virtual void unkSlot2F();
    virtual void unkSlot30();
    virtual void unkSlot31();
    virtual void unkSlot32();
    virtual void unkSlot33();
    virtual void unkSlot34();
    virtual void unkSlot35();
    virtual void unkSlot36();
    virtual void unkSlot37();
    virtual void unkSlot38();
    virtual void unkSlot39();
    virtual void unkSlot3A();
    virtual void unkSlot3B();
    virtual void unkSlot3C();
    virtual void unkSlot3D();
    virtual void unkSlot3E();
    virtual void unkSlot3F();
    virtual void unkSlot40();
    virtual void unkSlot41();
    virtual void unkSlot42();
    virtual void unkSlot43();
    virtual void unkSlot44();
    virtual void unkSlot45();
    virtual void unkSlot46();
    virtual void unkSlot47();
    virtual void unkSlot48();
    virtual void unkSlot49();
    virtual void unkSlot4A();
    virtual void unkSlot4B();
    virtual void unkSlot4C();
    virtual void unkSlot4D();
    virtual void unkSlot4E();
    virtual void unkSlot4F();
    virtual void unkSlot50();
    virtual void unkSlot51();
    virtual void unkSlot52();
    virtual void unkSlot53();
    virtual void unkSlot54();
    virtual void unkSlot55();
    virtual void unkSlot56();
    virtual void unkSlot57();
    virtual void unkSlot58();
    virtual void unkSlot59();
    virtual void unkSlot5A();
    virtual void unkSlot5B();
    virtual void unkSlot5C();
    virtual void unkSlot5D();
    virtual void unkSlot5E();
    virtual void unkSlot5F();
    virtual void unkSlot60();
    virtual void unkSlot61();
    virtual void unkSlot62();
    virtual void unkSlot63();
    virtual void unkSlot64();
    virtual void unkSlot65();
    virtual void unkSlot66();
    virtual void unkSlot67();
    virtual void unkSlot68();
    virtual void unkSlot69();
    virtual void unkSlot6A();
    virtual void unkSlot6B();
    virtual void unkSlot6C();
    virtual void unkSlot6D();
    virtual void unkSlot6E();
    virtual NiAVObject* Get3D1(bool a_firstPerson) const;
    virtual NiAVObject* Get3D2() const;

    int GetProcessLevel();
    void SetAlpha(float a_alpha);

    unsigned char unkPadding08[0xF0];
    AIProcess* currentProcess;
};

extern Actor* playerSingleton;

static_assert(offsetof(Actor, currentProcess) == 0xF8, "Actor process offset");
static_assert(offsetof(NiAVObject, fadeAmount) == 0x100, "Scene object fade offset");
