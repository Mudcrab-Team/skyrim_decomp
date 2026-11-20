// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSStoryManagerQuestNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// QChildCount, GetChild: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// children, childCount: GUESS(low)
#pragma once

#include <cstdint>

class BGSStoryManagerTreeForm;

class BGSStoryManagerQuestNode
{
public:
    std::uint32_t QChildCount() const;
    BGSStoryManagerTreeForm* GetChild(std::uint32_t index) const;

private:
    std::uint8_t padding00[0x48];
    BGSStoryManagerTreeForm** children;
    std::uint8_t padding50[8];
    std::uint32_t childCount;
};
