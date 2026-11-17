// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); signatures and type names are hypotheses.
// TESBoundObject::Clone3D: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// TESBoundObject::ReplaceModel: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObject.cpp:92
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObject.cpp:105
// TESObject and TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
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
#include "../fo4p198c_bound/TESForm.h"
class NiAVObject; class TESObjectREFR; class TESWaterForm; class BGSVoiceType;
class TESModel { public: static const char* GetModel(TESForm*); };
class TESObject : public TESForm {
public:
    virtual void Unk_3B();
    virtual bool IsBoundAnimObject();
    virtual TESWaterForm* GetWaterType() const;
    virtual bool IsAutoCalc() const;
    virtual void SetAutoCalc(bool);
    virtual NiAVObject* Clone3D(TESObjectREFR*, bool);
    virtual void UnClone3D(TESObjectREFR*);
    virtual bool IsMarker();
    virtual bool IsOcclusionMarker();
    virtual bool ReplaceModel();
    virtual std::uint32_t IncRef();
    virtual std::uint32_t DecRef();
    virtual NiAVObject* LoadGraphics(TESObjectREFR*);
};
class TESBoundObject : public TESObject {
public:
    virtual void SetObjectVoiceType(BGSVoiceType*);
    virtual BGSVoiceType* GetObjectVoiceType() const;
    NiAVObject* Clone3D(TESObjectREFR*, bool) override;
    bool ReplaceModel() override;
    virtual NiAVObject* Clone3D(TESObjectREFR*);
    virtual bool ReplaceModel(const char*);
};
