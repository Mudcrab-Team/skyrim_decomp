// Origin: original reconstruction
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// BGSAssociationType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSAssociationType::~BGSAssociationType, BGSAssociationType::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/TESForm.h"

// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// value, names, flags: GUESS(low); pooled string values and association flags.
class BSFixedString {
public:
    BSFixedString(const char* = nullptr);
    ~BSFixedString();
    BSFixedString& operator=(const BSFixedString&);
    const char* value;
};
class BGSAssociationType : public TESForm
{
public:
    BGSAssociationType();
    virtual ~BGSAssociationType();  // compared: 0x389800 (scalar deleting destructor)
    BSFixedString names[4];
    std::uint32_t flags;
    virtual void InitializeData();  // compared: 0x389430
};
