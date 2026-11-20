// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BGSKeyword, SetFormEditorID, formEditorID, BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MakeFixedString: GUESS(low); the temporary comes from a call whose returned address feeds the assignment, as a by-value return does
#pragma once

#include <cstdint>

class BSFixedString
{
public:
	BSFixedString(const BSFixedString& a_rhs);
	~BSFixedString();
	BSFixedString& operator=(const BSFixedString& a_rhs);

	const char* _data;  // 00
};

BSFixedString MakeFixedString(const char* a_string);

class BGSKeyword
{
public:
	bool SetFormEditorID(const char* a_str);

	std::uint8_t  unk00[0x20];   // 00
	BSFixedString formEditorID;  // 20
};
