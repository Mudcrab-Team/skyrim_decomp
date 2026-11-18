// Inferred names: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction informed by CommonLibSSE-NG declarations (MIT).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BGSExplosion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)

// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <cstdint>
// BaseFormComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
// BSFixedString, _data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct BSFixedString { const char* _data; };
// TESFileContainer, array: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESFileArray;
struct TESFileContainer { TESFileArray* array; };
// TESForm, sourceFiles, formFlags, formID, inGameFormFlags, formType, pad1B, pad1C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESForm : public BaseFormComponent { public: TESFileContainer sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
// TESFullName, fullName: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESFullName : public BaseFormComponent { public: BSFixedString fullName; };
// TESModel, model, textures, addons, numTextures, numAddons, pad24: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
namespace BSResource { struct ID; }
class TESModel : public BaseFormComponent { public: BSFixedString model; BSResource::ID* textures; std::uint32_t* addons; std::uint16_t numTextures; std::uint16_t numAddons; std::uint32_t pad24; };
// NiNPShortPoint3, x, y, z, TESObject, TESBoundObject, boundData, boundMin, boundMax, pad2C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiNPShortPoint3 { std::int16_t x, y, z; };
class TESObject : public TESForm {};
class TESBoundObject : public TESObject { public: struct BOUND_DATA { NiNPShortPoint3 boundMin, boundMax; }; BOUND_DATA boundData; std::uint32_t pad2C; };
// TESEnchantableForm, formEnchanting, castingType, amountofEnchantment, pad14: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class EnchantmentItem;
class TESEnchantableForm : public BaseFormComponent { public: EnchantmentItem* formEnchanting; std::uint16_t castingType; std::uint16_t amountofEnchantment; std::uint32_t pad14; };
// BGSPreloadable: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSPreloadable : public BaseFormComponent {};
// TESImageSpaceModifiableForm, imageSpaceModifying: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESImageSpaceModifier;
class TESImageSpaceModifiableForm : public BaseFormComponent { public: TESImageSpaceModifier* imageSpaceModifying; };
// BGSImpactData, IMPACT_DATA_DATA, effectDuration, orient, angleThreshold, placementRadius, soundLevel, flags, resultOverride, unk16, data, decalTextureSet: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSTextureSet;
class BGSImpactData : public TESForm, public TESModel { public: struct IMPACT_DATA_DATA { float effectDuration; std::uint32_t orient; float angleThreshold; float placementRadius; std::uint32_t soundLevel; std::uint8_t flags; std::uint8_t resultOverride; std::uint16_t unk16; }; IMPACT_DATA_DATA data; BGSTextureSet* decalTextureSet; };
// BGSImpactDataSet: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindImpact: GUESS(low)
class BGSImpactDataSet { public: BGSImpactData* FindImpact(); };
// BGSExplosionData, light, sound1, sound2, impactDataSet: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESObjectLIGH; class BGSSoundDescriptorForm;
struct BGSExplosionData { TESObjectLIGH* light; BGSSoundDescriptorForm* sound1; BGSSoundDescriptorForm* sound2; BGSImpactDataSet* impactDataSet; };
// BGSExplosion, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function261400: GUESS(low)
class BGSExplosion : public TESBoundObject, public TESFullName, public TESModel, public TESEnchantableForm, public BGSPreloadable, public TESImageSpaceModifiableForm { public: BGSTextureSet* Function261400(); BGSExplosionData data; };
