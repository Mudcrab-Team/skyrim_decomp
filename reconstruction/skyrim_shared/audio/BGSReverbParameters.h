// Source exposure: mixed
// BGSReverbParameters: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSReverbParameters.h, include/RE/B/BSIReverbType.h and include/RE/T/TESForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// DoGetRoomLevel, DoGetRoomHFLevel, DoGetReflectionLevel, DoGetReverbLevel, DoGetDiffusion, DoGetDensity, DoGetHFReference, DoGetDecayTime, DoGetDecayHFRatio, DoGetReflectionDelay, InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// kDecayTimeScale: GUESS(low); global float at address 0x1b5bdc4, the multiplier applied to the decay time
// kReflectionDelayScale: GUESS(low); global float at address 0x1834b48, the multiplier applied to the reflection delay
#pragma once
extern float kDecayTimeScale;
extern float kReflectionDelayScale;
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: virtual void InitializeData(); void* files; unsigned flags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; };
class BSIReverbType { public:
 virtual int DoGetRoomLevel() const = 0; virtual int DoGetRoomHFLevel() const = 0;
 virtual float DoGetDecayTime() const = 0; virtual float DoGetDecayHFRatio() const = 0;
 virtual int DoGetReflectionLevel() const = 0; virtual float DoGetReflectionDelay() const = 0;
 virtual int DoGetReverbLevel() const = 0; virtual float DoGetReverbDelay() const = 0;
 virtual float DoGetDiffusion() const = 0; virtual float DoGetDensity() const = 0; virtual float DoGetHFReference() const = 0;
};
class BGSReverbParameters : public TESForm, public BSIReverbType { public:
 struct ReverbParams { unsigned short decayTime, hfReference; signed char roomFilter, roomHFFilter, reflections, reverb; unsigned char decayHFRatio, reflectionDelay, reverbDelay, diffusionPct, densityPct, pad; } data;
 float DoGetReverbDelay() const override;
 int DoGetRoomLevel() const override; int DoGetRoomHFLevel() const override; int DoGetReflectionLevel() const override; int DoGetReverbLevel() const override;
 float DoGetDiffusion() const override; float DoGetDensity() const override; float DoGetHFReference() const override;
 float DoGetDecayTime() const override; float DoGetDecayHFRatio() const override; float DoGetReflectionDelay() const override;
 void InitializeData() override;
};
