// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// QuickSortSortKeys: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Globals: GUESS(low); placeholder name
#pragma once

struct SortKey;

struct SortKey
{
    unsigned __int64 value;
};



inline int CompareSortKeys(SortKey* current, SortKey* other)
{
    if (current->value < other->value)
        return -1;
    else if (current->value > other->value)
        return 1;
    return 0;
}

struct Globals
{
};
