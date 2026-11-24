// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x12329c0 MovementTweenerAgentNodeFollower::Function12329c0
// Adapted bodies: none
#include "MovementTweenerAgentNodeFollower_12329c0.h"

#include <cstring>

void MovementTweenerAgentNodeFollower::Function12329c0(const NodeFollowerState& a_src, NodeFollowerState& a_dst)
{
    std::memcpy(a_dst.unk00, a_src.unk00, sizeof(a_dst.unk00));
    a_dst.unk20 = a_src.unk20;
    a_dst.unk24 = a_src.unk24;
    a_dst.unk28 = a_src.unk28;
    a_dst.unk2C = a_src.unk2C;
    a_dst.unk30 = a_src.unk30;
}
