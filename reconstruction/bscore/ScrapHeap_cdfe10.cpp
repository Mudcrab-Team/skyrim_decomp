// CI hash: 0xcdfe10 ?Functioncdfe10@ScrapHeap@@QEAAXXZ
// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScrapHeap: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// ScrapHeap::Functioncdfe10: GUESS(low)
// ScrapHeap::activeCount: GUESS(low)
// 0xcdfe10 ScrapHeap::Functioncdfe10
#include "ScrapHeap_cdfe10.h"

// Retire one active allocation before finishing its block.
void ScrapHeap::Functioncdfe10()
{
    --activeCount;
    FinishBlock(this);
}
