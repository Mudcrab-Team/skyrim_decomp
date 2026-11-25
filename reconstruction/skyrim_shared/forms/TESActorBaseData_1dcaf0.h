// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TESActorBaseData::GetTemplateUseFlag follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesactorbasedata.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesactorbasedata.cpp:107
// TESActorBaseData, ACTOR_BASE_DATA, actorData, templateUseFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESActorBaseData::GetTemplateUseFlag: CRASHLOGGER_PDB(59818@2026.10.24)
// unk00, unk08, unk14: GUESS(low)
#pragma once

#include <cstdint>

struct ACTOR_BASE_DATA
{
    std::uint8_t unk08[0x12];
    std::uint16_t templateUseFlags;
    std::uint8_t unk14[4];
};

class TESActorBaseData
{
public:
    bool GetTemplateUseFlag(int a_flag);

    std::uint8_t unk00[8];
    ACTOR_BASE_DATA actorData;
};
