// Source exposure: mixed (local binary analysis and community headers).
// Code origin: original reconstruction; community inline implementations were inspected.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); target ownership uncertain, BSFixedStringCS remains possible
// entry: GUESS(low); pointer storage at offset zero
// BSFixedString::BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); operation and target ownership are provisional
// Adapted bodies: none; original spelling after inspecting community implementations.
// 0xeb1040 BSFixedString::BSFixedString
#include "BSFixedString_eb1040.h"
#include <intrin.h>

BSFixedString::BSFixedString(const BSFixedString& other)
{
    const char* value = other.entry;
    if (value) {
        auto flags = reinterpret_cast<volatile long*>(const_cast<char*>(value) - 16);
        long current = *flags;
        long previous;
        do {
            previous = current;
            if ((current & 0x7fff) >= 0x7fff) {
                break;
            }
            // Pool references are shared by concurrent string owners.
            current = _InterlockedCompareExchange(flags, current + 1, current);
        } while (current != previous);
    }
    entry = value;
}
