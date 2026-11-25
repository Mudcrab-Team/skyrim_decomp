// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: QuickSortSortKeys.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:4151
// 0xeba2c0 QuickSortSortKeys
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bssystem/archive.cpp:2901
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bssystem/archive.cpp:2887
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:4141
// Adapted helpers: QuickSortSortKeys, CompareSortKeys
// CI hash: 0xeba2c0 ?QuickSortSortKeys@@YAXPEAPEAUSortKey@@HH@Z
#include "Globals_eba2c0.h"

void QuickSortSortKeys(SortKey** entries, int left, int right)
{
    int e = left;
    int l = right;
    int c = left;
    SortKey* j = entries[c];
    while (left < right)
    {
        {
            int p;
            SortKey* pCurrent;
            while ((pCurrent = entries[right], p = CompareSortKeys(pCurrent, j)) >= 0 && left < right)
                --right;
        }
        if (left != right)
        {
            entries[left] = entries[right];
            ++left;
        }
        {
            int p;
            SortKey* pCurrent;
            while ((pCurrent = entries[left], p = CompareSortKeys(pCurrent, j)) <= 0 && left < right)
                ++left;
        }
        if (left != right)
        {
            entries[right] = entries[left];
            --right;
        }
    }
    entries[left] = j;
    c = left;
    left = e;
    right = l;
    if (left < c)
        QuickSortSortKeys(entries, left, c - 1);
    if (right > c)
        QuickSortSortKeys(entries, c + 1, right);
}
