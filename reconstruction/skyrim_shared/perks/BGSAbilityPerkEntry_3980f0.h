// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAbilityPerkEntry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSPerkEntry: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BGSPerkEntry
{
public:
    virtual ~BGSPerkEntry() {}

private:
    std::uint8_t padding08[0x8];
};

class BGSAbilityPerkEntry : public BGSPerkEntry
{
public:
    BGSAbilityPerkEntry();
    ~BGSAbilityPerkEntry() override = default;

private:
    std::uint8_t padding10[0x8];
};
static_assert(sizeof(BGSAbilityPerkEntry) == 0x18, "observed allocation size");
