// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations; the destructor body equals the FNV sibling's one-line body
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesimagespace.cpp:68
// TESImageSpace, TESImageSpace::~TESImageSpace, TESImageSpace::InitializeData, TESImageSpace::Load: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20, unknown28, unknown30, unknown38, unknown40, unknown48, unknown50, unknown58, unknown60, unknown68: GUESS(low); the compared destructor reads none of them
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

class TESImageSpace : public TESForm
{
public:
    virtual ~TESImageSpace();  // compared: 0x2a67e0  // slot 00
    void InitializeData() override;  // 04
    bool Load(TESFile* a_mod) override;  // 06
    TESImageSpace();

    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
};
static_assert(sizeof(TESImageSpace) == 0x70, "TESImageSpace size");
