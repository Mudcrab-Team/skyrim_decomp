// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESCondition4a6d90::ClearAllConditions, treated as adapted: shaped like TESCondition::~TESCondition (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/T/TESCondition.cpp:57, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionItem4a6d90, TESCondition4a6d90, ClearAllConditions, next, unk08, head: GUESS(low)
#pragma once

#include <cstdint>

struct ConditionItem4a6d90
{
    ~ConditionItem4a6d90();

    ConditionItem4a6d90* next;  // 0x00
    std::uint64_t unk08[6];     // 0x08
};
static_assert(sizeof(ConditionItem4a6d90) == 0x38, "ConditionItem4a6d90 size");

class TESCondition4a6d90
{
public:
    void ClearAllConditions();

    ConditionItem4a6d90* head;  // 0x00
};
static_assert(sizeof(TESCondition4a6d90) == 0x8, "TESCondition4a6d90 size");
