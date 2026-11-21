// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction; body written from the listing.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xaa2c40 hkReferencedObject::CalcContentStatistics
// hkReferencedObject::CalcContentStatistics: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_specialClass, StatBuf, GetStatFlag, CollectStat: GUESS(low)
// Adapted bodies: none
#include "hkReferencedObject.h"

void hkReferencedObject::CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const
{
    if (!a_class) {
        return;
    }
    if (a_class == &g_specialClass) {
        return;
    }
    StatBuf buf;
    if (*GetStatFlag(&buf, a_class)) {
        CollectStat(this, a_class, a_collector);
    }
}
