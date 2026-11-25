// Code origin: original declarations with the labelled community layouts and member names. Stamped as a twin of matched 0x38cf10 (skyrim_shared/dialogue/BGSDialogueBranch): source copied, names replaced by placeholders.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold at the pinned checkouts.
// ::flags, ::quest, ::startingTopic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESQuest, TESTopic: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque, only used by pointer
// Function122d600, Owner122d600: GUESS(low) STANDIN
#pragma once
#include "BGSDialogueBranch.h"

class Owner122d600 : public TESForm {
public:
    void InitializeData() override;  // 04

    void Function122d600(TESTopic* a_topic);

    std::uint32_t flags;          // 20
    TESQuest*     quest;          // 28
    TESTopic*     startingTopic;  // 30
};

