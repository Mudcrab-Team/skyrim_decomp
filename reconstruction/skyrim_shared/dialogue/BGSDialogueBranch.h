// Code origin: original declarations with the labelled community layouts and member names.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold at the pinned checkouts.
// BGSDialogueBranch, BGSDialogueBranch::InitializeData, ::flags, ::quest, ::startingTopic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESQuest, TESTopic: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque, only used by pointer
#pragma once

#include <cstdint>

#include "skyrim_shared/forms/TESForm.h"

class TESQuest;
class TESTopic;

class BGSDialogueBranch : public TESForm {
public:
    void InitializeData() override;  // 04

    void Function38cf10(TESTopic* a_topic);

    std::uint32_t flags;          // 20
    TESQuest*     quest;          // 28
    TESTopic*     startingTopic;  // 30
};
