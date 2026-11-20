// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSReverbParameters::DoGetReverbDelay: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSReverbParameters.cpp:262
// BGSReverbParameters: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSReverbParameters.h, include/RE/B/BSIReverbType.h and include/RE/T/TESForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* files; unsigned flags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; };
class BSIReverbType { public:
 virtual int DoGetRoomLevel() const = 0; virtual int DoGetRoomHFLevel() const = 0;
 virtual float DoGetDecayTime() const = 0; virtual float DoGetDecayHFRatio() const = 0;
 virtual int DoGetReflectionLevel() const = 0; virtual float DoGetReflectionDelay() const = 0;
 virtual int DoGetReverbLevel() const = 0; virtual float DoGetReverbDelay() const = 0;
 virtual float DoGetDiffusion() const = 0; virtual float DoGetDensity() const = 0; virtual float DoGetHFReference() const = 0;
};
class BGSReverbParameters : public TESForm, public BSIReverbType { public:
 struct ReverbParams { unsigned short decayTime, hfReference; signed char roomFilter, roomHFFilter, reflections, reverb, decayHFRatio, reflectionDelay; unsigned char reverbDelay, diffusionPct, densityPct, pad; } data;
 float DoGetReverbDelay() const override;
};
