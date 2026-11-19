// Source exposure: mixed (pinned image listings, project form units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations adapted from the project and CommonLibSSE-NG.
// TESNPC: EXE_RTTI
// SetDefaultOutfit, SetSleepOutfit, GetHeadPartByType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyObjectBounds, GetBoundMinimum, GetBoundMaximum, Function3b0080, Function3b0090: GUESS(low)
// Function3bc100, GetBehaviorGraphName, CopyBehaviorGraphName, Function3be960, Function3be9c0: GUESS(low)
// Function3bea20, Function3bea80, Function3beda0, Function3bedf0: GUESS(low)
// ResetFaceData, GetFaceMorph, GetFacePart, GetFaceParameter, GetFaceSetting: GUESS(low)
// SetClass, GetSkin, MergeHeadPartsInto, MergeHeadParts, MergeHeadPartList: GUESS(low)
// GetSoundLevel, GetRaceHeight, Function3c90c0: GUESS(low)
// ActorReference, HeadPartList, RelationshipList, minimum, maximum: STANDIN GUESS(low)
// PackageData, packageOverrides, padding: STANDIN GUESS(low)
// BGSHeadPart, BGSOutfit, BGSRelationship, TESObjectARMO, TESPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESClass, TESRace, TESFullName, NiPoint3, BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FaceData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class ActorReference;
class BGSHeadPart;
class BGSOutfit;
class BGSRelationship;
class RelationshipList;
class TESObjectARMO;
class TESPackage;
class TESClass;
class TESRace;
struct HeadPartList;
struct FaceData;

// x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiPoint3 { float x, y, z; };

// NiNPShortPoint3, BOUND_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiNPShortPoint3 { std::int16_t x, y, z; };
struct BOUND_DATA { NiNPShortPoint3 minimum, maximum; };
static_assert(sizeof(BOUND_DATA) == 0xC, "object bounds size");

class BSFixedString
{
public:
    void AssignFrom(const BSFixedString& source);
    std::uint32_t Length() const;

private:
    const void* entry;
};

class TESFullName
{
public:
    virtual ~TESFullName();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(TESFullName* source);
    virtual std::uint32_t GetFullNameLength() const;
    virtual const char* GetFullName() const;

private:
    BSFixedString fullName;
};

class TESNPC
{
public:
    void CopyObjectBounds(const TESNPC& source);
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
    static void Function3c90c0();

private:
    // TESForm::AddChange and preceding slots follow the project form declarations.
    virtual ~TESNPC();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(TESNPC* source);
    virtual void InitializeData();
    virtual void ClearData();
    virtual bool Load(void* file);
    virtual bool LoadPartial(void* file);
    virtual bool LoadEdit(void* file);
    virtual TESNPC* CreateDuplicateForm(bool createId, void* context);
    virtual bool AddChange(std::uint32_t bits);

    // IsFemale: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
    // Function3c5960, Function3c85f0, kDefaultOutfitChange, kSleepOutfitChange, kClassChange: STANDIN GUESS(low)
    std::int32_t IsFemale();
    TESPackage* Function3c85f0(ActorReference* actor, const void* list) const;
    void Function3c5960(BGSHeadPart* const* source, std::uint32_t count, BGSHeadPart**& destination, std::uint32_t& size);

    enum : std::uint32_t { kClassChange = 1u << 10, kDefaultOutfitChange = 1u << 12, kSleepOutfitChange = 1u << 13 };

    // TESForm::formFlags, TESBoundObject::boundData, TESRaceForm::race, TESFullName::fullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // npcClass, shortName, defaultOutfit, sleepOutfit, headParts: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // numHeadParts, unk242, soundLevel, relationships, faceData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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
