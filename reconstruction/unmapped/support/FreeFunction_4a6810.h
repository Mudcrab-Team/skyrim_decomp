// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function4a6810, treated as adapted: shaped like TESCondition::~TESCondition (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/T/TESCondition.cpp:57, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionNode4a6810, ConditionList4a6810, Function4a6810, next, unk08, head, list: GUESS(low)
#pragma once

#include <cstdint>

struct ConditionNode4a6810
{
    ~ConditionNode4a6810();

    ConditionNode4a6810* next;  // 0x00
    std::uint64_t unk08[6];     // 0x08
};
static_assert(sizeof(ConditionNode4a6810) == 0x38, "ConditionNode4a6810 size");

struct ConditionList4a6810
{
    ConditionNode4a6810* head;  // 0x00
};
static_assert(sizeof(ConditionList4a6810) == 0x8, "ConditionList4a6810 size");

void Function4a6810(ConditionList4a6810* list);
