// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3c74a0 TESNPC::GetTextForParsedSubTag
// Adapted bodies: none
#include "TESNPC_3c74a0.h"

// Resolves text replacement sub-tags for NPC pronouns, race, short name, or base form fallback.
const char* TESNPC::GetTextForParsedSubTag(const BSFixedString& a_tag) const
{
    const char* result = nullptr;
    const char* tag = a_tag.data;
    if (tag == g_subTag0) {
        result = (GetSex() == 0) ? g_maleText0 : g_femaleText0;
    } else if (tag == g_subTag1) {
        result = (GetSex() == 0) ? g_maleText1 : g_femaleText1;
    } else if (tag == g_subTag2) {
        result = (GetSex() == 0) ? g_maleText2 : g_femaleText2;
    } else if (tag == g_subTag3) {
        result = (GetSex() == 0) ? g_maleText3 : g_femaleText3;
    } else if (tag == g_subTag4) {
        result = (GetSex() == 0) ? g_maleText4 : g_femaleText4;
    } else if (tag == g_subTag5) {
        result = (GetSex() == 0) ? g_maleText5 : g_femaleText5;
    } else if (tag == g_subTagRace) {
        result = race->GetName();
    } else if (tag == g_subTag6) {
        result = (GetSex() == 0) ? g_maleText6 : g_femaleText6;
    } else if (tag == g_subTagShortName) {
        result = GetShortNameInline();
    } else {
        result = TESForm::GetTextForParsedSubTag(a_tag);
    }
    return result;
}
