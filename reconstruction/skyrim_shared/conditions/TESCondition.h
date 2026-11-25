// Source exposure: mixed
// 0x4a6df0 compared function
// Origin: independently decoded target, anonymous sibling and public declarations.
// Code origin: written from the listing for the compared functions; IsTrue declaration adapted from a sibling and public declarations.
// Adapted bodies: none in this header.
// TESCondition::IsTrue: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESCondition.cpp:349
// ConditionCheckParams: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/T/TESCondition.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4a6df0 TESCondition::Function4a6df0
// 0x4a6c10 TESCondition::Function4a6c10
#pragma once

#include <cstdint>

struct ConditionNode
{
    ConditionNode* next;         // 00
    std::uint8_t pad08[0x28];    // 08
    std::uint8_t flag30;         // 30
};
class TESObjectREFR; class TESQuest; class BGSStoryEvent; class BGSPackageDataList;
struct ConditionCheckParams { TESObjectREFR* action; TESObjectREFR* target; TESQuest* quest; BGSStoryEvent* event; void* unknown; bool flag; BGSPackageDataList* packageData; };
struct ConditionItemIsTrue {};
class TESCondition
{
public:
    bool IsTrue(TESObjectREFR*, TESObjectREFR*) const;
    bool IsTrue(ConditionCheckParams&, ConditionItemIsTrue&) const;
    void Function4a6df0();  // compared: 0x4a6df0
    void Function4a6c10(ConditionNode* newNode);  // compared: 0x4a6c10

    ConditionNode* head;  // 00
};
