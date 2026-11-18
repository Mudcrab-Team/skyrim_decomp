// ActiveEffect: GUESS(low) STANDIN
/*
 * ActiveEffect: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x5da320 21 bytes; RVA 0x5c3d30 28 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis, community-headers.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); unverified against this build.
 * No external body adapted. Partial interfaces are stand-ins.
 */
#pragma once
#include <cstdint>
// ActiveEffect, ActiveEffect::Forward5da320, ActiveEffect::WeaponForm, EffectSetting::Call14b4f0: GUESS(low) STANDIN
class EffectSetting; class TESForm;
class ActiveEffect { public: EffectSetting* GetBaseEffect(); void* Forward5da320(); TESForm* WeaponForm(); };

/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

// ActiveEffect::GetBaseEffect: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91, permission)
// BaseFormComponent, TESForm, TESFullName, BGSMenuDisplayObject, BGSKeywordForm, EffectSetting, EffectSetting::EffectSettingData, BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// The interfaces below expose documented data prefixes and omit unneeded virtual methods and later fields.
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent() = 0; virtual void ClearDataComponent() = 0; virtual void CopyComponent(BaseFormComponent*); };
class TESFileArray; class TESBoundObject; class BGSKeyword;
class BSFixedString { const char* data; };
class TESForm : public BaseFormComponent { public: TESFileArray* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
class TESFullName : public BaseFormComponent { public: BSFixedString fullName; };
class BGSMenuDisplayObject : public BaseFormComponent { public: TESBoundObject* menuDispObject; };
class BGSKeywordForm : public BaseFormComponent { public: BGSKeyword** keywords; std::uint32_t numKeywords; std::uint32_t pad14; };
class EffectSetting : public TESForm, public TESFullName, public BGSMenuDisplayObject, public BGSKeywordForm { public:
    struct EffectSettingData { std::uint32_t flags; float baseCost; TESForm* associatedForm; };
    void* Call14b4f0();
    bool (*filterValidationFunction)(EffectSetting*, void*); void* filterValidationItem; EffectSettingData data;
};
static_assert(sizeof(TESForm) == 0x20, "TESForm prefix size");
static_assert(sizeof(TESFullName) == 0x10, "TESFullName size");
static_assert(sizeof(BGSMenuDisplayObject) == 0x10, "BGSMenuDisplayObject size");
static_assert(sizeof(BGSKeywordForm) == 0x18, "BGSKeywordForm size");
// BaseFormComponent::InitializeDataComponent, BaseFormComponent::ClearDataComponent, BaseFormComponent::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESForm::sourceFiles, TESForm::formFlags, TESForm::formID, TESForm::inGameFormFlags, TESForm::formType, TESForm::pad1B, TESForm::pad1C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESFullName::fullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSMenuDisplayObject::menuDispObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSKeywordForm::keywords, BGSKeywordForm::numKeywords, BGSKeywordForm::pad14: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// EffectSetting::filterValidationFunction, EffectSetting::filterValidationItem, EffectSetting::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// EffectSetting::EffectSettingData::flags, EffectSetting::EffectSettingData::baseCost, EffectSetting::EffectSettingData::associatedForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESFileArray, TESBoundObject, BGSKeyword: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
