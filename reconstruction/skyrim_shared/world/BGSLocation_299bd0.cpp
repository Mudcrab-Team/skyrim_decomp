// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x299bd0 BGSLocation::sub_1402427F0
// Adapted bodies: none
#include "BGSLocation_299bd0.h"

// Walks parent locations until one has the given keyword, returning that location or null.
BGSLocation* BGSLocation::sub_1402427F0(const BGSKeyword* a_keyword)
{
    BGSLocation* loc = this;
    if (a_keyword) {
        bool found = false;
        while (loc && !found) {
            if (!loc->HasKeyword(a_keyword)) {
                loc = loc->parentLoc;
            } else {
                found = true;
            }
        }
    }
    return loc;
}
