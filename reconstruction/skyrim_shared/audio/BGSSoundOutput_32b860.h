// Source exposure: mixed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSSoundOutput::DoGetAudibility: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:129
// BGSSoundOutput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSSoundOutput.h, include/RE/B/BSISoundOutputModel.h and include/RE/T/TESForm.h.
// names: GUESS(low); signatures and global interpretation remain provisional.
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
#pragma once
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* files; unsigned flags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; };
class BSISoundOutputModel { public:
 struct BSIAttenuationCharacteristics { virtual ~BSIAttenuationCharacteristics(); virtual float GetMaxDistance() const = 0; virtual float GetMinDistance() const = 0; virtual unsigned char GetCurveValue(unsigned) const = 0; };
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
extern const float MaxSoundDistance;
class BGSSoundOutput : public TESForm, public BSISoundOutputModel { public:
 struct Data { unsigned char flags, unk1, unk2, reverbSendPct; } data;
 unsigned outputType;
 BSIAttenuationCharacteristics* attenuation;
 bool DoGetAudibility(float) const override;
};
