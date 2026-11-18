// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSReverbParameters::~BGSReverbParameters: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSReverbParameters.cpp:33
// BGSReverbParameters: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/B/BGSReverbParameters.h, include/RE/B/BSIReverbType.h, include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// names: GUESS(low); constructor is represented to emit the destructor.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class TESFileArray; class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: ~TESForm() override; TESFileArray* sourceFiles; unsigned formFlags, formID; unsigned short inGameFormFlags; unsigned char formType; };
class BSIReverbType { public: virtual int DoGetRoomLevel() const = 0; virtual int DoGetRoomHFLevel() const = 0; virtual float DoGetDecayTime() const = 0; virtual float DoGetDecayHFRatio() const = 0; virtual int DoGetReflectionLevel() const = 0; virtual float DoGetReflectionDelay() const = 0; virtual int DoGetReverbLevel() const = 0; virtual float DoGetReverbDelay() const = 0; virtual float DoGetDiffusion() const = 0; virtual float DoGetDensity() const = 0; virtual float DoGetHFReference() const = 0; };
class BGSReverbParameters : public TESForm, public BSIReverbType { public: struct ReverbParams { std::uint16_t decayTime,hfReference; std::int8_t roomFilter,roomHFFilter,reflections,reverb,decayHFRatio,reflectionDelay,reverbDelay,diffusionPct,densityPct; }; BGSReverbParameters(); ~BGSReverbParameters() override; int DoGetRoomLevel() const override; int DoGetRoomHFLevel() const override; float DoGetDecayTime() const override; float DoGetDecayHFRatio() const override; int DoGetReflectionLevel() const override; float DoGetReflectionDelay() const override; int DoGetReverbLevel() const override; float DoGetReverbDelay() const override; float DoGetDiffusion() const override; float DoGetDensity() const override; float DoGetHFReference() const override; ReverbParams data; };
static_assert(sizeof(BGSReverbParameters)==0x38, "reverb layout");
