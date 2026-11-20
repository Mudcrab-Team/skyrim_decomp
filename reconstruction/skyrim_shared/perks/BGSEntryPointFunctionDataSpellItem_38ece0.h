// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSEntryPointFunctionDataSpellItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSEntryPointFunctionData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BGSEntryPointFunctionData
{
public:
    virtual ~BGSEntryPointFunctionData() {}
};

class BGSEntryPointFunctionDataSpellItem : public BGSEntryPointFunctionData
{
public:
    BGSEntryPointFunctionDataSpellItem();
    ~BGSEntryPointFunctionDataSpellItem() override = default;

private:
    std::uint8_t padding08[0x8];
};
static_assert(sizeof(BGSEntryPointFunctionDataSpellItem) == 0x10, "observed allocation size");
