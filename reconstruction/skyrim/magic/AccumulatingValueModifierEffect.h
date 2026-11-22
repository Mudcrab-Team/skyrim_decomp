// Source exposure: mixed
// 0x5ba3d0 compared function
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// ValueModifierEffect::ShouldModifyOnFinish, AccumulatingValueModifierEffect::ShouldModifyOnStart, AccumulatingValueModifierEffect::ShouldModifyOnUpdate: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ValueModifierEffect.cpp:165
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp:75
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp:81
// EffectSetting, ActiveEffect, ValueModifierEffect, AccumulatingValueModifierEffect: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/E/EffectSetting.h, include/RE/A/ActiveEffect.h, include/RE/V/ValueModifierEffect.h and include/RE/A/AccumulatingValueModifierEffect.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// Function5ba3d0, valueA0, g_defaultAccumulateValue: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* sourceFiles; unsigned int formFlags; unsigned int formID; unsigned short inGameFormFlags; unsigned char formType; };
class TESFullName : public BaseFormComponent { public: const char* fullName; };
class BGSMenuDisplayObject : public BaseFormComponent { public: void* menuDisplayObject; };
class BGSKeywordForm : public BaseFormComponent { public: void** keywords; unsigned int numKeywords; };
class EffectSetting : public TESForm, public TESFullName, public BGSMenuDisplayObject, public BGSKeywordForm { public: void* filterValidationFunction; void* filterValidationItem; struct EffectSettingData { unsigned int flags; } data; };
class ActiveEffect { public: EffectSetting* GetBaseObject() const; };
class ValueModifierEffect : public ActiveEffect { public: bool ShouldModifyOnStart(); bool ShouldModifyOnUpdate() const; bool ShouldModifyOnFinish() const; };
class AccumulatingValueModifierEffect : public ValueModifierEffect { public: bool ShouldModifyOnStart(); bool ShouldModifyOnUpdate() const; void Function5ba3d0(); std::uint8_t pad00[0xA0]; float valueA0; };

extern const float g_defaultAccumulateValue;
