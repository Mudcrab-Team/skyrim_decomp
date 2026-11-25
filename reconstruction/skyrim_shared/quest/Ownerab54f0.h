// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations. Stamped as a twin of matched 0x537f10 (skyrim_shared/quest/BGSStoryManagerQuestNode_537f10): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionab54f0, Ownerab54f0: GUESS(low) STANDIN
// GetChild, children, childCount: GUESS(low) STANDIN
#pragma once
#include "BGSStoryManagerQuestNode_537f10.h"

class Ownerab54f0
{
public:
    std::uint32_t Functionab54f0() const;
    BGSStoryManagerTreeForm* GetChild(std::uint32_t index) const;

private:
    std::uint8_t padding00[0x48];
    BGSStoryManagerTreeForm** children;
    std::uint8_t padding50[8];
    std::uint32_t childCount;
};

