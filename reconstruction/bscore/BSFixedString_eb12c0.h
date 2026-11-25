// Source exposure: mixed (local binary analysis and community headers).
// Code origin: original reconstruction; community inline implementations were inspected.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); target ownership uncertain, BSFixedStringCS remains possible
// entry: GUESS(low); pointer storage at offset zero
// 0xeb12c0 BSFixedString::operator!=
// operator!=: GUESS(low); inferred operation, target ownership is provisional
#pragma once

class BSFixedString
{
public:
    bool operator!=(const char* other) const;
    const char* entry;
};
static_assert(sizeof(BSFixedString) == 8, "pointer storage");
