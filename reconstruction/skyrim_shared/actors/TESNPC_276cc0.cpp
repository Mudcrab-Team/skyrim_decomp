// Source exposure: mixed (pinned image listings, project form units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations from the pinned listings using the cited layouts.
// Adapted bodies: SetDefaultOutfit and SetSleepOutfit follow CommonLibSSE-NG@b93280e src/RE/T/TESNPC.cpp:230 and :265 (MIT).
// 0x276cc0 TESNPC::CopyObjectBounds
// 0x277a00 TESNPC::GetBoundMinimum
// 0x277a40 TESNPC::GetBoundMaximum
// 0x3b0080 TESNPC::Function3b0080
// 0x3b0090 TESNPC::Function3b0090
// 0x3bc100 TESNPC::Function3bc100
// 0x3be2a0 TESNPC::GetBehaviorGraphName
// 0x3be360 TESNPC::CopyBehaviorGraphName
// 0x3be960 TESNPC::Function3be960
// 0x3be9c0 TESNPC::Function3be9c0
// 0x3bea20 TESNPC::Function3bea20
// 0x3bea80 TESNPC::Function3bea80
// 0x3beda0 TESNPC::Function3beda0
// 0x3bedf0 TESNPC::Function3bedf0
// 0x3bf1e0 TESNPC::ResetFaceData
// 0x3bf300 TESNPC::GetFaceMorph
// 0x3bf400 TESNPC::GetFacePart
// 0x3bf460 TESNPC::GetFaceParameter
// 0x3bf490 TESNPC::GetFaceSetting
// 0x3bf500 TESNPC::SetDefaultOutfit
// 0x3bf520 TESNPC::SetSleepOutfit
// 0x3bf560 TESNPC::SetClass
// 0x3bf580 TESNPC::GetSkin
// 0x3bfbb0 TESNPC::GetHeadPartByType
// 0x3c5b00 TESNPC::MergeHeadPartsInto
// 0x3c5b30 TESNPC::MergeHeadParts
// 0x3c5b80 TESNPC::MergeHeadPartList
// 0x3c6160 TESNPC::GetSoundLevel
// 0x3c6570 TESNPC::GetRaceHeight
// 0x3c90c0 TESNPC::Function3c90c0
#include "TESNPC_276cc0.h"

#include <new>

// TESRace::rootBehaviorGraphNames, TESRace::skin: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// height, Function3e3650: STANDIN GUESS(low)
class TESRace
{
public:
    const BSFixedString* Function3e3650(std::int32_t sex) const;

    std::uint8_t padding00[0x58];
    TESObjectARMO* skin;
    std::uint8_t padding60[0x98];
    float height[2];
    std::uint8_t padding100[0x138];
    BSFixedString rootBehaviorGraphNames[2];
};

// type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSHeadPart
{
public:
    std::uint8_t padding[0x6C];
    std::uint32_t type;
};

// FaceData, morphs, parts: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct FaceData
{
    float morphs[19];
    std::int32_t parts[4];
};

// ActorReference, PackageData, Function1728d0, extraList: STANDIN GUESS(low)
// Function187ab0, Function187c30, Function187db0, Function187f30: STANDIN GUESS(low)
class PackageData
{
public:
    TESPackage* Function187ab0(ActorReference* actor) const;
    TESPackage* Function187c30(ActorReference* actor) const;
    TESPackage* Function187db0(ActorReference* actor) const;
    TESPackage* Function187f30(ActorReference* actor) const;
};

struct ExtraDataList
{
    const PackageData* Function1728d0() const;
};

struct ActorReference
{
    std::uint8_t padding[0x70];
    ExtraDataList extraList;
};

// RelationshipExtremes, first, second, lowerBound, upperBound, Function3c9eb0: STANDIN GUESS(low)
struct RelationshipExtremes
{
    BGSRelationship* first;
    BGSRelationship* second;
    std::int32_t lowerBound;
    std::int32_t upperBound;
};

class RelationshipList
{
public:
    void Function3c9eb0(RelationshipExtremes& result) const;
};

// FaceParameter, FaceSetting, FaceSettingPair, faceParameters, faceSettings: STANDIN GUESS(low)
struct FaceParameter
{
    std::uint32_t mode;
    const void* fallback;
    const void* nonnegative;
};

struct FaceSetting
{
    std::uint8_t padding[8];
    std::int32_t value;
};

struct FaceSettingPair
{
    const FaceSetting* setting;
    const FaceSetting* pairedSetting;
};

extern const FaceParameter faceParameters[];
extern const FaceSettingPair faceSettings[];

// HeadPartBlock, HeadPartList, entries, count, next, headPartBlocks: STANDIN GUESS(low)
struct HeadPartBlock
{
    HeadPartBlock* next;
    std::uint8_t padding[0x1F8];
};

struct HeadPartList
{
    std::uint8_t padding00[8];
    BGSHeadPart* const* entries;
    std::uint8_t padding10[8];
    std::uint32_t count;
};

extern HeadPartBlock* headPartBlocks;

// defaultFaceData, emptyBehaviorGraphName, defaultRaceHeight, Function41d3f0: STANDIN GUESS(low)
extern FaceData defaultFaceData;
extern const BSFixedString emptyBehaviorGraphName;
extern const float defaultRaceHeight;
std::uint32_t Function41d3f0(std::uint8_t level);

void TESNPC::CopyObjectBounds(const TESNPC& source)
{
    boundData = source.boundData;
}

NiPoint3 TESNPC::GetBoundMinimum() const
{
    return {static_cast<float>(boundData.minimum.x),
             static_cast<float>(boundData.minimum.y),
             static_cast<float>(boundData.minimum.z)};
}

NiPoint3 TESNPC::GetBoundMaximum() const
{
    return {static_cast<float>(boundData.maximum.x),
             static_cast<float>(boundData.maximum.y),
             static_cast<float>(boundData.maximum.z)};
}

bool TESNPC::Function3b0080() const
{
    return (formFlags >> 19) & 1;
}

void TESNPC::Function3b0090(bool value)
{
    if (value) {
        formFlags |= 1u << 19;
    } else {
        formFlags &= ~(1u << 19);
    }
}

void TESNPC::Function3bc100(std::uint8_t value)
{
    unk242 = value;
}

const BSFixedString* TESNPC::GetBehaviorGraphName()
{
    if (auto* npcRace = race) {
        return npcRace->Function3e3650(IsFemale());
    }
    return &emptyBehaviorGraphName;
}

bool TESNPC::CopyBehaviorGraphName(BSFixedString& output)
{
    if (auto* npcRace = race) {
        output.AssignFrom(npcRace->rootBehaviorGraphNames[IsFemale()]);
        return output.Length() != 0;
    }
    return false;
}

TESPackage* TESNPC::Function3be960(ActorReference* actor) const
{
    if (auto* packageData = actor->extraList.Function1728d0()) {
        if (auto* package = packageData->Function187ab0(actor)) {
            return package;
        }
    }
    return Function3c85f0(actor, packageOverrides[0]);
}

TESPackage* TESNPC::Function3be9c0(ActorReference* actor) const
{
    if (auto* packageData = actor->extraList.Function1728d0()) {
        if (auto* package = packageData->Function187c30(actor)) {
            return package;
        }
    }
    return Function3c85f0(actor, packageOverrides[1]);
}

TESPackage* TESNPC::Function3bea20(ActorReference* actor) const
{
    if (auto* packageData = actor->extraList.Function1728d0()) {
        if (auto* package = packageData->Function187db0(actor)) {
            return package;
        }
    }
    return Function3c85f0(actor, packageOverrides[2]);
}

TESPackage* TESNPC::Function3bea80(ActorReference* actor) const
{
    if (auto* packageData = actor->extraList.Function1728d0()) {
        if (auto* package = packageData->Function187f30(actor)) {
            return package;
        }
    }
    return Function3c85f0(actor, packageOverrides[3]);
}

BGSRelationship* TESNPC::Function3beda0() const
{
    if (relationships) {
        RelationshipExtremes extremes{nullptr, nullptr, INT32_MIN, INT32_MAX};
        relationships->Function3c9eb0(extremes);
        return extremes.first;
    }
    return nullptr;
}

BGSRelationship* TESNPC::Function3bedf0() const
{
    if (relationships) {
        RelationshipExtremes extremes{nullptr, nullptr, INT32_MIN, INT32_MAX};
        relationships->Function3c9eb0(extremes);
        return extremes.second;
    }
    return nullptr;
}

void TESNPC::ResetFaceData()
{
    if (faceData != &defaultFaceData) {
        ::operator delete(faceData, sizeof(FaceData));
        faceData = &defaultFaceData;
    }
}

float TESNPC::GetFaceMorph(std::int32_t index) const
{
    return faceData->morphs[index];
}

std::int32_t TESNPC::GetFacePart(std::int32_t index) const
{
    return faceData->parts[index];
}

const void* TESNPC::GetFaceParameter(std::int32_t index, float value)
{
    const auto& parameter = faceParameters[index];
    const void* result = parameter.fallback;
    if (parameter.mode == 2 && value >= 0.0f) {
        result = parameter.nonnegative;
    }
    return result;
}

std::int32_t TESNPC::GetFaceSetting(std::int32_t index)
{
    return faceSettings[index].setting->value;
}

bool TESNPC::SetDefaultOutfit(BGSOutfit* value)
{
    defaultOutfit = value;
    return AddChange(kDefaultOutfitChange);
}

bool TESNPC::SetSleepOutfit(BGSOutfit* value)
{
    sleepOutfit = value;
    return AddChange(kSleepOutfitChange);
}

bool TESNPC::SetClass(TESClass* value)
{
    npcClass = value;
    return AddChange(kClassChange);
}

TESObjectARMO* TESNPC::GetSkin() const
{
    auto* result = skin;
    if (!result && race) {
        result = race->skin;
    }
    return result;
}

BGSHeadPart* TESNPC::GetHeadPartByType(std::uint32_t type) const
{
    const std::uint32_t count = numHeadParts;
    BGSHeadPart** const volatile& parts = headParts;
    BGSHeadPart* result = nullptr;
    std::uint32_t index = 0;
    do {
        if (index >= count) {
            break;
        }
        auto* part = parts[index];
        if (part && part->type == type) {
            result = part;
        }
        ++index;
    } while (!result);
    return result;
}

void TESNPC::MergeHeadPartsInto(const HeadPartList& source, BGSHeadPart**& parts, std::uint32_t& count)
{
    if (source.count) {
        Function3c5960(source.entries, source.count, parts, count);
    }
}

void TESNPC::MergeHeadParts(BGSHeadPart* const* source, std::uint32_t count)
{
    std::uint32_t size = numHeadParts;
    Function3c5960(source, count, headParts, size);
    numHeadParts = static_cast<std::uint8_t>(size);
}

void TESNPC::MergeHeadPartList(const HeadPartList& source)
{
    if (source.count) {
        std::uint32_t size = numHeadParts;
        Function3c5960(source.entries, source.count, headParts, size);
        numHeadParts = static_cast<std::uint8_t>(size);
    }
}

std::uint32_t TESNPC::GetSoundLevel() const
{
    return Function41d3f0(soundLevel);
}

float TESNPC::GetRaceHeight()
{
    if (auto* npcRace = race) {
        const std::int32_t sex = IsFemale();
        if (static_cast<std::uint32_t>(sex) <= 1) {
            return npcRace->height[sex];
        }
        return 0.0f;
    }
    return defaultRaceHeight;
}

void TESNPC::Function3c90c0()
{
    while (auto* block = headPartBlocks) {
        headPartBlocks = block->next;
        ::operator delete(block, sizeof(HeadPartBlock));
    }
}
