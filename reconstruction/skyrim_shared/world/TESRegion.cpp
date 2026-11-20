// Source exposure: mixed (target listing, public declarations, sibling hint).
// Origin: public declarations and anonymous sibling code.
// TESRegion::Validate: SIBLING(fo4-private@1b765c70, author-permission); adapted region validation.
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegion.cpp:263
// TESRegion, TESRegionDataList, TESRegionPointList, TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations adapted from include/RE/T/TESRegion.h and include/RE/T/TESForm.h.
// Validate, RegionPointNode: GUESS(low); names and signatures remain unverified.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x24faa0 TESRegion::Validate
#include "TESRegion.h"
bool TESRegion::Validate()
{
    RegionPointNode* list = pointLists;
    if (!list || !dataList || !dataList->Validate()) return false;
    do {
        if (!list->item) break;
        if (!list->item->Validate(true)) return false;
        list = list->next;
    } while (list);
    return true;
}
