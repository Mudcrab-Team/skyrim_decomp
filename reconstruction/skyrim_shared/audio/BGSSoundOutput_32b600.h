// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSSoundOutput, TESForm, BSISoundOutputModel, data, type: GUESS(low); adjusted target access corroborates the selected field.
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
#include <cstdint>
class TESFileArray; class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent()=0; virtual void ClearDataComponent()=0; virtual void CopyComponent(BaseFormComponent*); }; struct TESFileContainer { TESFileArray* array; }; class TESForm: public BaseFormComponent { public: TESFileContainer sourceFiles; std::uint32_t formFlags,formID; std::uint16_t inGameFormFlags; std::uint8_t formType; }; class BSISoundOutputModel { public: virtual ~BSISoundOutputModel(); virtual bool DoGetUsesHRTF() const=0; virtual bool DoGetHasSpeakerBias() const=0; }; class BGSSoundOutput: public TESForm, public BSISoundOutputModel { public: enum class Type:std::uint32_t { kUsesHRTF=0,kDefinedSpeakerOutput=1 }; struct Data { std::uint8_t flags, unk1, unk2, reverbSendPct; }; bool DoGetHasSpeakerBias() const override; Data data; Type type; };
