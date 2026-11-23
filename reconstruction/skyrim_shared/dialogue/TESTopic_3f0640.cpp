// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3f0640 QuickSortTopicCompare
// Adapted bodies: none
#include "TESTopic_3f0640.h"

int QuickSortTopicCompare(TESTopic* a, TESTopic* b)
{
    return CompareEditorIds(a->GetFormEditorID(), b->GetFormEditorID());
}
