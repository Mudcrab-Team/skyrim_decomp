// Source exposure: mixed (pinned image and public declarations).
// Code origin: reconstructed from the pinned image; matches the cited FNV sibling body.
// BSMultiBoundNode::UpdateUpwardPass: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); adapted to target observations.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00c20000_od.cpp:1273
// 0xff3380 BSMultiBoundNode::UpdateUpwardPass
#include "BSMultiBoundNode_ff3380.h"

void BSMultiBoundNode::UpdateUpwardPass()
{
    NiNode::UpdateUpwardPass();
    UpdateWorldBound();
}
