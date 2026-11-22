// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ReferenceEffect: GUESS(low); the class is the placeholder owner, layout stand-in
// Detach: CRASHLOGGER_PDB(59818@2026.10.24)
// DetachImpl, controller, ownController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReferenceEffectController, RemoveHitEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

class ReferenceEffect;

class ReferenceEffectController
{
public:
    virtual ~ReferenceEffectController();                       // 00
    virtual void unk01();                                       // 01
    virtual void unk02();                                       // 02
    virtual void unk03();                                       // 03
    virtual void unk04();                                       // 04
    virtual void unk05();                                       // 05
    virtual void unk06();                                       // 06
    virtual void unk07();                                       // 07
    virtual void unk08();                                       // 08
    virtual void unk09();                                       // 09
    virtual void RemoveHitEffect(ReferenceEffect* a_refEffect); // 0A
};

class ReferenceEffect
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual void unk26();
    virtual void unk27();
    virtual void unk28();
    virtual void unk29();
    virtual void unk2A();
    virtual void unk2B();
    virtual void unk2C();
    virtual void unk2D();
    virtual void unk2E();
    virtual void unk2F();
    virtual void unk30();
    virtual void unk31();
    virtual void unk32();
    virtual void unk33();
    virtual void unk34();
    virtual void unk35();
    virtual void unk36();
    virtual void unk37();
    virtual void unk38();
    virtual void unk39();
    virtual void unk3A();
    virtual void unk3B();
    virtual void unk3C();
    virtual void unk3D();
    virtual void DetachImpl();  // 3E

    void Detach();  // compared: 0x5db5e0

    void* pad08[5];                         // 08
    ReferenceEffectController* controller;  // 30
    unsigned char pad38[9];                 // 38
    bool ownController;                     // 41
};
