// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT), and no external implementation body or layout is copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSBehaviorGraphModel, BGSBehaviorGraphModel::~BGSBehaviorGraphModel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>

class BGSBehaviorGraphModel {
public:
    BGSBehaviorGraphModel();
    virtual ~BGSBehaviorGraphModel();  // compared: 0x3eb7c0 (scalar deleting destructor)

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
};
static_assert(sizeof(BGSBehaviorGraphModel) == 0x28, "BGSBehaviorGraphModel size");
