// Source exposure: mixed (local binary analysis and community headers).
// Code origin: original reconstruction; community inline implementations were inspected.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); target ownership uncertain, BSFixedStringCS remains possible
// entry: GUESS(low); pointer storage at offset zero
// operator!=: GUESS(low); inferred operation, target ownership is provisional
// Adapted bodies: none; original spelling after inspecting community implementations.
// 0xeb12c0 BSFixedString::operator!=
#include "BSFixedString_eb12c0.h"
#include <cstring>

bool BSFixedString::operator!=(const char* other) const
{
    if (entry) {
        if (other) {
            return _stricmp(entry, other) != 0;
        }
        return true;
    }
    return other != nullptr;
}
