// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0x29e720 BGSKeyword::SetFormEditorID
#include "BGSKeyword_29e720.h"

bool BGSKeyword::SetFormEditorID(const char* a_str)
{
	formEditorID = MakeFixedString(a_str);
	return true;
}
