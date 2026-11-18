// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSSoundOutput::DoGetReverbSendLevel, BGSSoundOutput::DoGetSupportsMonitor: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:141
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:147
// BGSSoundOutput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSSoundOutput.h, include/RE/B/BSISoundOutputModel.h and include/RE/T/TESForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* files; unsigned flags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; };
class BSISoundOutputModel { public:
 struct BSIAttenuationCharacteristics;
 virtual ~BSISoundOutputModel();
 virtual bool DoGetUsesHRTF() const = 0;
 virtual bool DoGetHasSpeakerBias() const = 0;
 virtual bool DoGetSpeakerBias(unsigned, unsigned, float (&)[8]) const = 0;
 virtual bool DoGetAttenuatesWithDistance() const = 0;
 virtual bool DoGetAudibility(float) const = 0;
 virtual unsigned DoGetSupportedInputChannels() const = 0;
 virtual const BSIAttenuationCharacteristics* DoGetAttenuation() const = 0;
 virtual float DoGetReverbSendLevel() const = 0;
 virtual bool DoGetSupportsMonitor(unsigned) const = 0;
};
unsigned BigRumbleMonitor(); unsigned SmallRumbleMonitor();
class BGSSoundOutput : public TESForm, public BSISoundOutputModel { public:
 struct Data { unsigned char flags, unk1, unk2, reverbSendPct; } data;
 float DoGetReverbSendLevel() const override; bool DoGetSupportsMonitor(unsigned) const override;
};
