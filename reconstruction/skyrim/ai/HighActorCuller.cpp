// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original; the listing of the pinned image and community declarations only
// 0x73c720 HighActorCuller::Function73c720: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Adapted bodies: none
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
#include "HighActorCuller.h"

// CullerFallback, CullerSubObject, CullerTail: GUESS(low); the three unnamed callees and the global of the compared listing.
void CullerFallback(HighActorCuller* a_self);
void CullerSubObject(void* a_self, void* a_data);
void CullerTail(void* a_global, HighActorCuller* a_self);
extern void* g_cullerGlobal;

void HighActorCuller::Function73c720(void* a_arg)
{
    if (field148 == nullptr) {
        CullerFallback(this);
    } else {
        field28 = a_arg;
        CullerSubObject(reinterpret_cast<std::uint8_t*>(this) + 0x10,
                        reinterpret_cast<std::uint8_t*>(a_arg) + 0x150);
    }
    CullerTail(g_cullerGlobal, this);
}
