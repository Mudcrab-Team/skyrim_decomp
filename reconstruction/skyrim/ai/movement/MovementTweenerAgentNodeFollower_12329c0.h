// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// MovementTweenerAgentNodeFollower, Function12329c0, NodeFollowerState: GUESS(low)
#pragma once

#include <cstdint>

struct NodeFollowerState
{
    float unk00[8];
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
};

class MovementTweenerAgentNodeFollower
{
public:
    void Function12329c0(const NodeFollowerState& a_src, NodeFollowerState& a_dst);  // compared: 0x12329c0
};
