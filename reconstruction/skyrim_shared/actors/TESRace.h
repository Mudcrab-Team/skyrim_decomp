// Code origin: original declarations with the labelled community layouts and member names.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Adapted bodies: BSFixedString::data and ::c_str from CharmedBaryon/CommonLibSSE-NG b93280e (MIT)
// include/RE/B/BSFixedString.h; tools/check_origin.py reports none other above its threshold.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESRace, TESRace::~TESRace, ::GetPlayable, ::GetFormEditorID, ::data, ::bodyPartData, ::formEditorID, ::baseMoveTypes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRace::GetBodyPartData, ::GetMovementType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// RACE_DATA, RACE_DATA::flags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares an enumeration over uint32, here a plain word
// RACE_DATA::unk00, ::unk24: GUESS(low); opaque members around flags
// TESRace::unk20, ::unk18C, ::unk270, ::unk2E8, ::unk42C: GUESS(low); opaque blocks between the members above
// BGSBodyPartData, BGSMovementType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations
// BGSDefaultObjectManager::GetDefaultMovementType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); the callee at RVA 0x393860, a static function here
// defaultBodyPartData: GUESS(low); the global pointer at RVA 0x31e0178 returned when the race has no body part data
// BSFixedString, BSFixedString::_data, ::EMPTY, ::data, ::c_str: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG templates the class, EMPTY is an external constant at RVA 0x1b58020 bound by hint
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// TESRace::validEquipTypes, TESRace::faceRelatedData, TESRace::FaceRelatedData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRace::QCanUseMeleeWeapons: CRASHLOGGER_PDB(59818@2026.10.24)
// TESRace::GetValidEquipTypes: GUESS(low)
#pragma once

#include <cstdint>

#include "skyrim_shared/forms/TESForm.h"

class BGSBodyPartData;
class BGSMovementType;
class BGSTextureSet;

class BSFixedString {
public:
    static const char EMPTY[1];

    const char* data() const { return _data ? _data : EMPTY; }
    const char* c_str() const { return data(); }

    const char* _data;  // 00
};

class BGSDefaultObjectManager {
public:
    static BGSMovementType* GetDefaultMovementType(std::int32_t a_index);
};

extern BGSBodyPartData* defaultBodyPartData;

struct RACE_DATA {
    std::uint8_t  unk00[0x20];  // 00
    std::uint32_t flags;        // 20
    std::uint8_t  unk24[0x80];  // 24
};
static_assert(sizeof(RACE_DATA) == 0xA4, "layout");

class TESRace : public TESForm {
public:
    TESRace();
    ~TESRace() override;  // 00

    bool        GetPlayable() const override;           // 19
    const char* GetFormEditorID() const override;       // 32

    BGSBodyPartData* GetBodyPartData();
    BGSMovementType* GetMovementType(std::int32_t a_index);

    bool QCanUseMeleeWeapons() const;
    bool Function3e82e0() const;
    BGSTextureSet* Function3e8610(std::int32_t a_sex, std::uint32_t a_index) const;

    std::uint8_t     unk20[0xC8];         // 20
    RACE_DATA        data;                // E8
    std::uint8_t     unk18C[0xDC];        // 18C
    BGSBodyPartData* bodyPartData;        // 268
    std::uint8_t     unk270[0x70];        // 270
    BSFixedString    formEditorID;        // 2E0
    std::uint8_t     unk2E8[0x140];         // 2E8
    std::uint32_t    validEquipTypes;     // 428
    std::uint8_t     unk42C[0x4C];        // 42C
    BGSMovementType* baseMoveTypes[6];    // 478
    struct FaceDetailTextures {
        BGSTextureSet** data;              // 00
        std::uint8_t unknown08[0x8];       // 08
        std::uint32_t size;                // 10
    };

    struct FaceRelatedData {
        std::uint8_t unk00[0x98];          // 00
        FaceDetailTextures* faceDetailsTextureSets;  // 98
    };

    FaceRelatedData* faceRelatedData[2];   // 4A8

private:
    std::uint32_t GetValidEquipTypes(std::uint32_t a_mask) const { return validEquipTypes & a_mask; }
};
static_assert(sizeof(TESRace) == 0x4B8, "layout");
