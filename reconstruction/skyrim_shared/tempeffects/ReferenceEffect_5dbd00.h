// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ReferenceEffect: GUESS(low); the class is the placeholder owner, layout stand-in
// ClearController: SYMBOLS(fo4-pdb)
// controller, ownController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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
    void ClearController();  // compared: 0x5dbd00

    void* unk00[6];                         // 00
    ReferenceEffectController* controller;  // 30
    unsigned char unk38[9];                 // 38
    bool ownController;                     // 41
};
