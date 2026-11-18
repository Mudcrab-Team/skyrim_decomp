// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT), and no external implementation body or layout is copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSkillPerkTreeNode, BGSSkillPerkTreeNode::~BGSSkillPerkTreeNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>

class BGSSkillPerkTreeNode {
public:
    BGSSkillPerkTreeNode();
    virtual ~BGSSkillPerkTreeNode();  // compared: 0x446e50 (scalar deleting destructor)

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
};
static_assert(sizeof(BGSSkillPerkTreeNode) == 0x68, "BGSSkillPerkTreeNode size");
