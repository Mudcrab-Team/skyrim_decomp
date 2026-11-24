// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSQuestObjective.cpp:59
// BGSQuestObjective, BGSQuestObjective::InitializeData, BGSLocalizedString, BGSLocalizedString::SetString: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to the members the body uses
// BGSQuestObjective::index, ownerQuest, numTargets, flags, initialized, state, TESQuest, TESQuestTarget: CRASHLOGGER_PDB(59818@2026.10.24)
// strDisplayText, usIndex, pOwnerQuest, uiNumTargets, uiFlags, pTargetsA, bInitialized, cState: GUESS(low); the sibling's member names, laid out as the listing shows
// unk00: GUESS(low)
#pragma once

#include <cstdint>

class TESQuest;
class TESQuestTarget;

class BGSLocalizedString
{
public:
    void SetString(const char* apString);

    const char* unk00;
};

class BGSQuestObjective
{
public:
    void InitializeData();

    BGSLocalizedString strDisplayText;  // 00
    TESQuest*          pOwnerQuest;     // 08
    TESQuestTarget**   pTargetsA;       // 10
    std::uint32_t      uiNumTargets;    // 18
    std::uint16_t      usIndex;         // 1C
    bool               bInitialized;    // 1E
    std::uint8_t       cState;          // 1F
    std::uint32_t      uiFlags;         // 20
    std::uint32_t      pad24;           // 24
};
static_assert(sizeof(BGSQuestObjective) == 0x28, "BGSQuestObjective size");
