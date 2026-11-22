// Source exposure: mixed (pinned image and public declarations).
// Code origin: original declaration of the multi-bound upward update override.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00c20000_od.cpp:1274 (BSMultiBoundNode::UpdateUpwardPass)
// BSMultiBoundNode, UpdateUpwardPass, UpdateWorldBound: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include "NiNode_ee1560.h"

class BSMultiBoundNode : public NiNode
{
public:
    void UpdateUpwardPass() override;
};
