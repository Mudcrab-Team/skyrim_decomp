// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TESIdleForm::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesidleform.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesidleform.cpp:55
// TESIdleForm, parentIdle, conditions, formFlags, TESForm::RecordFlags::kInitialized: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESIdleForm::ClearData: CRASHLOGGER_PDB(59818@2026.10.24)
// TESCondition: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESCondition::Clear, unk28, unk00, g_idleRegistrationEnabled, TestBit: GUESS(low)
// TESIdleForm::UnregisterIdleForm: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence) OBSERVED; Skyrim passes the child to the parent.
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESCondition
{
public:
    void Clear();

    void* unk00;
};

class TESIdleForm : public TESForm
{
public:
    void ClearData() override;
    void UnregisterIdleForm(TESIdleForm* a_idle);

    TESCondition conditions;
    std::uint8_t unk28[0x10];
    TESIdleForm* parentIdle;
};

extern __declspec(thread) bool g_idleRegistrationEnabled;
