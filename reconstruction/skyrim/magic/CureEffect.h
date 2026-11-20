// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// CureEffect::Start: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/CureEffect.cpp:58
// ActiveEffect, CureEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h and include/RE/C/CureEffect.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class ActiveEffect;
class MagicTarget { public: void Dispel(int); void Dispel(int, bool); };
struct Point3 { float x, y, z; };
struct EffectController { virtual ~EffectController(); ActiveEffect* effect; unsigned target; Point3 windPoint; };
struct SoundHandle { unsigned soundID; bool assumeSuccess; unsigned char pad; unsigned short pad2; unsigned state; };
class ActiveEffect {
public:
    virtual void Start();
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

class CureEffect : public ActiveEffect { public: int spellType, archetypeID; void Start() override; };
