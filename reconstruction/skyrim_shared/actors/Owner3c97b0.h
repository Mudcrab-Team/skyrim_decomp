// Source exposure: mixed (pinned image listings, project form units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations adapted from the project and CommonLibSSE-NG. Stamped as a twin of matched 0x3c90c0 (skyrim_shared/actors/TESNPC_276cc0): source copied, names replaced by placeholders.
// ActorReference, HeadPartList, RelationshipList: STANDIN GUESS(low)
// packageOverrides: STANDIN GUESS(low)
// BGSHeadPart, BGSOutfit, BGSRelationship, TESObjectARMO, TESPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESClass, TESRace, TESFullName, NiPoint3, BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FaceData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function3c97b0, Owner3c97b0, headPartBlocks_3c97b0: GUESS(low) STANDIN
// SetDefaultOutfit, SetSleepOutfit, GetHeadPartByType, CopyObjectBounds, GetBoundMinimum, GetBoundMaximum, Function3b0080, Function3b0090, Function3bc100, GetBehaviorGraphName, CopyBehaviorGraphName, Function3be960, Function3be9c0, Function3bea20, Function3bea80, Function3beda0, Function3bedf0, ResetFaceData, GetFaceMorph, GetFacePart, GetFaceParameter, GetFaceSetting, SetClass, GetSkin, MergeHeadPartsInto, MergeHeadParts, MergeHeadPartList, GetSoundLevel, GetRaceHeight, IsFemale, npcClass, shortName, defaultOutfit, sleepOutfit, headParts, numHeadParts, unk242, soundLevel, relationships, faceData: GUESS(low) STANDIN
#pragma once
#include "TESNPC_276cc0.h"
#include <new>

class Owner3c97b0
{
public:
    void CopyObjectBounds(const Owner3c97b0& source);
    NiPoint3 GetBoundMinimum() const;
    NiPoint3 GetBoundMaximum() const;
    bool Function3b0080() const;
    void Function3b0090(bool value);
    void Function3bc100(std::uint8_t value);
    const BSFixedString* GetBehaviorGraphName();
    bool CopyBehaviorGraphName(BSFixedString& output);
    TESPackage* Function3be960(ActorReference* actor) const;
    TESPackage* Function3be9c0(ActorReference* actor) const;
    TESPackage* Function3bea20(ActorReference* actor) const;
    TESPackage* Function3bea80(ActorReference* actor) const;
    BGSRelationship* Function3beda0() const;
    BGSRelationship* Function3bedf0() const;
    void ResetFaceData();
    float GetFaceMorph(std::int32_t index) const;
    std::int32_t GetFacePart(std::int32_t index) const;
    static const void* GetFaceParameter(std::int32_t index, float value);
    static std::int32_t GetFaceSetting(std::int32_t index);
    bool SetDefaultOutfit(BGSOutfit* value);
    bool SetSleepOutfit(BGSOutfit* value);
    bool SetClass(TESClass* value);
    TESObjectARMO* GetSkin() const;
    BGSHeadPart* GetHeadPartByType(std::uint32_t type) const;
    void MergeHeadPartsInto(const HeadPartList& source, BGSHeadPart**& parts, std::uint32_t& count);
    void MergeHeadParts(BGSHeadPart* const* source, std::uint32_t count);
    void MergeHeadPartList(const HeadPartList& source);
    std::uint32_t GetSoundLevel() const;
    float GetRaceHeight();
    static void Function3c97b0();

private:
    // TESForm::AddChange and preceding slots follow the project form declarations.
    virtual ~Owner3c97b0();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(Owner3c97b0* source);
    virtual void InitializeData();
    virtual void ClearData();
    virtual bool Load(void* file);
    virtual bool LoadPartial(void* file);
    virtual bool LoadEdit(void* file);
    virtual Owner3c97b0* CreateDuplicateForm(bool createId, void* context);
    virtual bool AddChange(std::uint32_t bits);

    // Function3c5960, Function3c85f0, kDefaultOutfitChange, kSleepOutfitChange, kClassChange: STANDIN GUESS(low)
    std::int32_t IsFemale();
    TESPackage* Function3c85f0(ActorReference* actor, const void* list) const;
    void Function3c5960(BGSHeadPart* const* source, std::uint32_t count, BGSHeadPart**& destination, std::uint32_t& size);

    enum : std::uint32_t { kClassChange = 1u << 10, kDefaultOutfitChange = 1u << 12, kSleepOutfitChange = 1u << 13 };

// TESForm::formFlags, TESBoundObject::boundData, TESRaceForm::race, TESFullName::fullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t padding08[8];
    std::uint32_t formFlags;
    std::uint8_t padding14[0xC];
    BOUND_DATA boundData;
    std::uint8_t padding2C[0xAC];
    TESFullName fullName;
    std::uint8_t paddingE8[0x20];
    TESObjectARMO* skin;
    std::uint8_t padding110[0x48];
    TESRace* race;
    std::uint8_t padding160[8];
    const void* packageOverrides[4];
    std::uint8_t padding188[0x38];
    TESClass* npcClass;
    std::uint8_t padding1C8[0x40];
    BSFixedString shortName;
    std::uint8_t padding210[8];
    BGSOutfit* defaultOutfit;
    BGSOutfit* sleepOutfit;
    std::uint8_t padding228[0x10];
    BGSHeadPart** headParts;
    std::uint8_t numHeadParts;
    std::uint8_t padding241;
    std::uint8_t unk242;
    std::uint8_t padding243[2];
    std::uint8_t soundLevel;
    std::uint8_t padding246[0xA];
    RelationshipList* relationships;
    FaceData* faceData;
};

