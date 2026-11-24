// Source exposure: mixed
// Code origin: written for this reconstruction from the listing; names and layout from the unit header.
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// ActiveEffect::GetVisualsTarget, ActiveEffect::CanFinish: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:12
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:203
// ActiveEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h, include/RE/M/MagicTarget.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class ActiveEffect;
class MagicItem { public: bool IsPermanent() const; };
class MagicTarget { public: virtual ~MagicTarget(); virtual bool AddTarget(void*); virtual void* GetTargetStatsObject(); };
struct Point3 { float x, y, z; };
struct EffectController { virtual ~EffectController(); ActiveEffect* effect; unsigned target; Point3 windPoint; };
struct SoundHandle { unsigned soundID; bool assumeSuccess; unsigned char pad; unsigned short pad2; unsigned state; };
struct EffectItemInfo { void* unk00; void* unk08; void* data; };
class ActiveEffect {
public:
    virtual void* GetVisualsTarget();
    virtual void* VirtualSlot1();
    virtual void* VirtualSlot2();
    virtual void* VirtualSlot3();
    virtual void* VirtualSlot4();
    virtual void* VirtualSlot5();
    virtual void* VirtualSlot6();
    virtual void* VirtualSlot7();
    virtual void* VirtualSlot8();
    virtual void* VirtualSlot9();
    virtual void* VirtualSlot10();
    virtual void* VirtualSlot11();
    virtual void* VirtualSlot12();
    bool CanFinish() const;
    EffectController hitEffectController;
    SoundHandle persistentSound;
    unsigned caster;
    void* sourceNode;
    MagicItem* spell;
    EffectItemInfo* effect;
    MagicTarget* target;
    void* source;
    void* hitEffects;
    void* displacementSpell;
    float elapsedSeconds, duration, magnitude;
    unsigned flags, conditionStatus;
    unsigned short uniqueID, pad86;
    unsigned castingSource;
public:
    void* Function5d3e00();
};
