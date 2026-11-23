// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1d89e0 BGSKeywordForm::HasKeyword
// Adapted bodies: none
#include "BGSKeywordForm_1d89e0.h"

bool BGSKeywordForm::HasKeyword(const BGSKeyword* a_keyword) const
{
    BGSKeyword* defaultKeyword = GetDefaultKeyword();
    if (defaultKeyword && defaultKeyword == a_keyword) {
        return true;
    }
    bool found = false;
    for (std::uint32_t i = 0; i < numKeywords && !found; ++i) {
        BGSKeyword* current = keywords[i];
        found = (current == a_keyword);
    }
    if (found) {
        return true;
    }
    return false;
}
