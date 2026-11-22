// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/testopicinfo.cpp:286
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/testopicinfo.cpp:294
// TESTopicInfo, TESTopicInfo::LoadGame, ::Revert, ::parentTopic, ::dataInfo, ::infoIndex, ::saidOnce: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTopicInfo::objConditions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; a pointer-sized block here, NG declares TESCondition
// TESTopicInfo::unk3B: GUESS(low); stands for favorLevel, data, fileOffset and the padding up to 0x48
#pragma once

#include <cstdint>

#include "skyrim_shared/forms/TESForm.h"

class TESTopic;
class TESTopicInfo;

class TESTopicInfo : public TESForm {
public:
    void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
    void Revert(BGSLoadFormBuffer* a_buf) override;    // 12

    TESTopic*     parentTopic;    // 20
    TESTopicInfo* dataInfo;       // 28
    void*         objConditions;  // 30
    std::uint16_t infoIndex;      // 38
    bool          saidOnce;       // 3A
    std::uint8_t  unk3B[0x0D];    // 3B
};
static_assert(sizeof(TESTopicInfo) == 0x48, "layout");
