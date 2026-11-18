// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSEntryPointFunctionData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSEntryPointFunctionData::Unk_05, BGSEntryPointFunctionData::~BGSEntryPointFunctionData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BGSEntryPointFunctionData
{
public:
    BGSEntryPointFunctionData();
    virtual std::uint16_t Unk_05();  // compared: 0x38e0c0
    virtual ~BGSEntryPointFunctionData();  // compared: 0x38ebb0 (scalar deleting destructor)
};
static_assert(sizeof(BGSEntryPointFunctionData) == 0x8, "BGSEntryPointFunctionData size");
