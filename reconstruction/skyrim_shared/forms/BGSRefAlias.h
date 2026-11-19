// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BGSRefAlias, BGSRefAlias::~BGSRefAlias, BGSRefAlias::Load, BGSRefAlias::InitItem, BGSRefAlias::QType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFile, TESForm, BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations only
// unknown28, unknown30, unknown38, unknown40: GUESS(low); the compared destructor reads none of them
#pragma once

#include <cstdint>
#include <cstddef>
#include "skyrim_shared/quest/BGSBaseAlias.h"

class TESFile;
class TESForm;
class BSFixedString;

class BGSRefAlias : public BGSBaseAlias
{
public:
    virtual ~BGSRefAlias();  // compared: 0x3a2e60  // slot 00
    // BGSBaseAlias in this tree declares no virtual members, so these omit override.
    virtual bool Load(TESFile* a_mod);  // 01
    virtual void InitItem(TESForm* a_form);  // 02
    virtual const BSFixedString& QType() const;  // 03
    BGSRefAlias();

    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
};
static_assert(sizeof(BGSRefAlias) == 0x48, "BGSRefAlias size");
