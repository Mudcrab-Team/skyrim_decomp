// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// EtherealizationEffect::Start, EtherealizationEffect::Finish: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EtherealizationEffect.cpp:21
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EtherealizationEffect.cpp:38
// ActiveEffect, EtherealizationEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h and include/RE/E/EtherealizationEffect.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class ActiveEffect;
class Actor { public: void SetGhost(bool); };
class MagicTarget { public: Actor* GetTargetAsActor(); };
struct Point3 { float x, y, z; };
struct EffectController { virtual ~EffectController(); ActiveEffect* effect; unsigned target; Point3 windPoint; };
struct SoundHandle { unsigned soundID; bool assumeSuccess; unsigned char pad; unsigned short pad2; unsigned state; };
class ActiveEffect {
public:
    virtual void Start();
    virtual void Finish();
    EffectController hitEffectController;
    SoundHandle persistentSound;
    unsigned caster;
    void* sourceNode;
    void* spell;
    void* effect;
    MagicTarget* target;
    void* source;
    void* hitEffects;
    void* displacementSpell;
    float elapsedSeconds, duration, magnitude;
    unsigned flags, conditionStatus;
    unsigned short uniqueID, pad86;
    unsigned castingSource;
};

class EtherealizationEffect : public ActiveEffect { public: void Start() override; void Finish() override; };
