// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BShkbAnimationGraph: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BShkbAnimationGraph::Functionbcae00: GUESS(low)
// 0xbcae00 BShkbAnimationGraph::Functionbcae00
#include "BShkbAnimationGraph_bcae00.h"

// Check whether the animation graph has an initialized behavior state chain.
bool BShkbAnimationGraph::Functionbcae00()
{
    if (!unk238 || !GetBehaviorState()) {
        return false;
    }

    GraphInner* inner = GetBehaviorState()->holder->inner;
    return inner && inner->unk10;
}
