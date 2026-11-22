// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5d2ed0 MagicTarget::VisitEffects
// Adapted bodies: none
#include "MagicTarget_5d2ed0.h"

void MagicTarget::VisitEffects(ForEachActiveEffectVisitor& visitor)
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    BSContainer::ForEachResult result = (node && node->item) ? BSContainer::ForEachResult::kContinue : BSContainer::ForEachResult::kStop;
    while (node && result == BSContainer::ForEachResult::kContinue) {
        result = visitor.Accept(node->item);
        node = node->next;
    }
}
