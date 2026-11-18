// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// TESBoundObject::Clone3D: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// TESBoundObject::ReplaceModel: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObject.cpp:92
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObject.cpp:105
// TESObject and TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "TESForm.h"
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
    virtual NiAVObject* Clone3D(TESObjectREFR*);
    virtual bool ReplaceModel(const char*);
    NiAVObject* Clone3D(TESObjectREFR*, bool) override;
    bool ReplaceModel() override;
};
