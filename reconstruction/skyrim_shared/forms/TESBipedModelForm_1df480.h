// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// TESBipedModelForm: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// BaseFormComponent, BSFixedString, TESModel, TESModelTextureSwap, TESBipedModelForm, model, textures, addons, numTextures, numAddons, pad24, alternateTextures, numAlternateTextures, pad34, worldModels: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function1df480, Apply, value: GUESS(low)
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class BSFixedString { public: const char* value; };
namespace BSResource { struct ID; }
class BGSTextureSet;
class TESModel : public BaseFormComponent {
public:
 BSFixedString model;
 BSResource::ID* textures;
 std::uint32_t* addons;
 std::uint16_t numTextures;
 std::uint16_t numAddons;
 std::uint32_t pad24;
};
class TESModelTextureSwap : public TESModel {
public:
 struct AlternateTexture;
 void Apply(void* value);
 AlternateTexture* alternateTextures;
 std::uint32_t numAlternateTextures;
 std::uint32_t pad34;
};
class TESBipedModelForm : public BaseFormComponent {
public:
 void Function1df480(void* value);
 TESModelTextureSwap worldModels[2];
};
