// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3f0590 IsEditorIdOrdered
// Adapted bodies: none
#include "TESTopic_3f0590.h"

int IsEditorIdOrdered(TESTopic* a, TESTopic* b)
{
    if (a) {
        if (!b) {
            return 1;
        }
        if (CompareEditorIds(a->GetFormEditorID(), b->GetFormEditorID()) >= 0) {
            return 1;
        }
    }
    return 0;
}
