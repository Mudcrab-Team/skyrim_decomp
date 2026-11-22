// Code origin: original declarations with the labelled community layouts and member names.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Adapted body: BSFixedString::c_str (the null test with the empty-string fallback), from
// CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSFixedString.h, MIT. Licence notice:
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Other bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold at the pinned checkouts.
// BGSHeadPart, BGSHeadPart::GetFormEditorID, ::SetFormEditorID, ::formEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSHeadPart::unk20: GUESS(low); unrecovered members before flags
// BSFixedString, BSFixedString::c_str, ::operator=, ::_data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; a single string pointer; operator= is declared and not defined, bound by hint to 0xeb1120
// BGSHeadPart::flags, BGSHeadPart::kPlayable: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "skyrim_shared/forms/TESForm.h"

class BSFixedString {
public:
    BSFixedString& operator=(const char* a_str);

    const char* c_str() const { return _data ? _data : ""; }

    const char* _data;  // 00
};

class BGSHeadPart : public TESForm {
public:
    const char* GetFormEditorID() const override;             // 32
    bool        SetFormEditorID(const char* a_str) override;  // 33

    bool Function3909e0() const;

    static constexpr std::uint8_t kPlayable = 1;

    std::uint8_t  unk20[0x48];   // 20
    std::uint8_t  flags;         // 68
    std::uint8_t  unk69[0xAF];   // 69
    BSFixedString formEditorID;  // 118
};
