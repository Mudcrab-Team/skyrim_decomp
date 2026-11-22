// Source exposure: mixed (pinned image listing and labelled declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing with labelled declarations.
// Adapted bodies: none.
// 0x391020 BGSHeadPart::GetFormEditorID
// 0x391210 BGSHeadPart::SetFormEditorID
// 0x3909e0 BGSHeadPart::Function3909e0
#include "BGSHeadPart.h"

const char* BGSHeadPart::GetFormEditorID() const
{
    return formEditorID.c_str();
}

bool BGSHeadPart::SetFormEditorID(const char* a_str)
{
    formEditorID = a_str;
    return true;
}
// Report whether the head part is available to the player.
bool BGSHeadPart::Function3909e0() const
{
    return flags & kPlayable;
}
