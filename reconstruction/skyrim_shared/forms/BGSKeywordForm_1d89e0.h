// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSKeywordForm, BGSKeyword, GetDefaultKeyword, HasKeyword, keywords, numKeywords: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk01, unk02, unk03, unk04: GUESS(low)
#pragma once
#include <cstdint>
class BGSKeyword;
class BGSKeywordForm {
public:
    virtual void unk00(); virtual void unk01(); virtual void unk02(); virtual void unk03(); virtual void unk04();
    virtual BGSKeyword* GetDefaultKeyword() const;
    virtual bool HasKeyword(const BGSKeyword* keyword) const;
    BGSKeyword** keywords;
    std::uint32_t numKeywords;
};
