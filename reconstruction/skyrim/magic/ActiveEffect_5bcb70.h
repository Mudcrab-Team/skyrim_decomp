// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// ActiveEffect::ShouldDispelOnDeath: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:238
// ActiveEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h, include/RE/E/Effect.h, include/RE/E/EffectSetting.h, include/RE/T/TESForm.h, include/RE/T/TESFullName.h, include/RE/B/BGSMenuDisplayObject.h and include/RE/B/BGSKeywordForm.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class ActiveEffect;
class Component { public: virtual ~Component(); };
class TESForm : public Component { public: void* files; unsigned flags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; };
class FullName : public Component { public: const char* name; };
class MenuDisplayObject : public Component { public: void* object; };
class KeywordForm : public Component { public: void** keywords; unsigned count; };
class EffectSetting : public TESForm, public FullName, public MenuDisplayObject, public KeywordForm { public: void* filter; void* filterItem; unsigned flags; };
struct EffectItem { float magnitude; unsigned area, duration; };
struct Effect { EffectItem item; unsigned pad; EffectSetting* baseEffect; };
struct Point3 { float x, y, z; };
struct EffectController { virtual ~EffectController(); ActiveEffect* effect; unsigned target; Point3 windPoint; };
struct SoundHandle { unsigned soundID; bool assumeSuccess; unsigned char pad; unsigned short pad2; unsigned state; };
class ActiveEffect {
public:
    virtual ~ActiveEffect();
    bool ShouldDispelOnDeath() const;
    EffectController hitEffectController;
    SoundHandle persistentSound;
    unsigned caster;
    void* sourceNode;
    void* spell;
    Effect* effect;
    void* target;
    void* source;
    void* hitEffects;
    void* displacementSpell;
    float elapsedSeconds, duration, magnitude;
    unsigned flags, conditionStatus;
    unsigned short uniqueID, pad86;
    unsigned castingSource;
};
