// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataDialogue.cpp:57
// TESDialoguePackageData, TESDialoguePackageData::TESDialoguePackageData: SIBLING(fo4-private@1b765c70, author-permission)
// TESDialoguePackageData::fFov, TESDialoguePackageData::ptopic, TESDialoguePackageData::pTargetLocation, TESDialoguePackageData::bNOHeadtracking, TESDialoguePackageData::bDoNotControlTarget, TESDialoguePackageData::bSayTo, TESDialoguePackageData::fDistanceStartTalking, TESDialoguePackageData::eTriggerType: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); the same names stand in the sibling constructor body, layout read from the listing
// PACK_DIALOGUE_DATA: GUESS(medium); name from the sibling constructor signature, layout read from the listing
// TESPackageData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTopic, PackageLocation: GUESS(low); forward declarations only
// unknown0c, unknown22, unknown29: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESTopic;
class PackageLocation;

class TESPackageData
{
public:
    virtual ~TESPackageData();  // 00
};

struct PACK_DIALOGUE_DATA
{
    float fFov;                       // 00
    std::uint32_t iTopicID;           // 04
    std::uint8_t bNOHeadtracking;     // 08
    std::uint8_t bDoNotControlTarget; // 09
    float fDistanceStartTalking;      // 0C
    std::uint8_t bSayTo;              // 10
    std::uint32_t eTriggerType;       // 14
};
static_assert(sizeof(PACK_DIALOGUE_DATA) == 0x18, "PACK_DIALOGUE_DATA size");

class TESDialoguePackageData : public TESPackageData
{
public:
    TESDialoguePackageData(PACK_DIALOGUE_DATA a_data);

    float fFov;                        // 08
    std::uint32_t unknown0c;           // 0C
    TESTopic* ptopic;                  // 10
    PackageLocation* pTargetLocation;  // 18
    std::uint8_t bNOHeadtracking;      // 20
    std::uint8_t bDoNotControlTarget;  // 21
    std::uint16_t unknown22;           // 22
    float fDistanceStartTalking;       // 24
    std::uint8_t bSayTo;               // 28
    std::uint8_t unknown29[3];         // 29
    std::uint32_t eTriggerType;        // 2C
};
static_assert(sizeof(TESDialoguePackageData) == 0x30, "TESDialoguePackageData size");
