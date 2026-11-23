// Source exposure: mixed (pinned target image, community headers).
// Code origin: adapted pinned community declarations and target-informed typed prefix stand-ins; no sibling body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; MIT.
// Prefix layout names and inferred members: GUESS(low) STANDIN
// Community type and member names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "../extradata/ExtraDataList.h"
namespace ResearchLayouts {
class TESObjectREFRExtraPrefixLayout : public TESForm, public BSHandleRefObject, public BSAnimationGraphEventSink, public IAnimationGraphManagerHolder {
public:
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void ForceEditorLocation(BGSLocation* location);
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual BGSScene* GetCurrentScene() const;
    virtual void SetCurrentScene(BGSScene* scene);
    REFR_LIGHT* GetMagicLightData() const; // Inferred unless supported by community declarations
    OBJECT_ACTION GetAction() const; // Inferred unless supported by community declarations
    bool HasAction(unsigned int flags) const; // Inferred unless supported by community declarations
    TESObjectREFR* GetActionReference() const; // Inferred unless supported by community declarations
    TESForm* GetOwner() const; // Inferred unless supported by community declarations
    MapMarkerData* GetMapMarkerData() const; // Inferred unless supported by community declarations
    REFR_LOCK* GetLock() const; // Inferred unless supported by community declarations
    TESObjectREFR* GetMultiBoundRef() const; // Inferred unless supported by community declarations
    BGSLocationRefType* GetLocationRefType() const; // Inferred unless supported by community declarations
    TESForm* GetEmittanceSource() const; // Inferred unless supported by community declarations
    TESObjectREFR* GetRandomTeleportMarker() const; // Inferred unless supported by community declarations
    bool IsOppositeEnableState() const; // Inferred unless supported by community declarations
    EnableStateChildren* GetEnableStateChildren() const; // Inferred unless supported by community declarations
    TESObjectREFR* GetLinkedRef(BGSKeyword* keyword); // Inferred unless supported by community declarations
    OBJ_REFR data;
    TESObjectCELL* parentCell;
    LOADED_REF_DATA* loadedData;
    ExtraDataList extraList;
};
static_assert(offsetof(TESObjectREFRExtraPrefixLayout, extraList) == 0x70, "target member address");
}
