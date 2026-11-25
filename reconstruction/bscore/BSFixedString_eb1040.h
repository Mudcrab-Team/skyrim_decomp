// Source exposure: mixed (local binary analysis and community headers).
// Code origin: original reconstruction; community inline implementations were inspected.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); target ownership uncertain, BSFixedStringCS remains possible
// entry: GUESS(low); pointer storage at offset zero
// 0xeb1040 BSFixedString::BSFixedString
// BSFixedString::BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); operation and target ownership are provisional
#pragma once

class BSFixedString
{
public:
    BSFixedString(const BSFixedString& other);
    const char* entry;
};
static_assert(sizeof(BSFixedString) == 8, "pointer storage");
