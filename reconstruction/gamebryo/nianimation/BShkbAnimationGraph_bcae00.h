// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BShkbAnimationGraph: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// GraphInner, GraphInner::unk00, GraphInner::unk10, GraphHolder, GraphHolder::inner, GraphState, GraphState::unk00, GraphState::holder, GraphBehavior, GraphBehavior::GetState, BShkbAnimationGraph::GetBehaviorState, BShkbAnimationGraph::Functionbcae00, BShkbAnimationGraph::unk00, BShkbAnimationGraph::behavior, BShkbAnimationGraph::unkF8, BShkbAnimationGraph::unk238: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct GraphInner
{
    std::uint8_t unk00[0x10];
    void* unk10;
};
static_assert(offsetof(GraphInner, unk10) == 0x10, "unk10 offset");

struct GraphHolder
{
    GraphInner* inner;
};

struct GraphState
{
    std::uint8_t unk00[0x10];
    GraphHolder* holder;
};
static_assert(offsetof(GraphState, holder) == 0x10, "holder offset");

class GraphBehavior
{
public:
    GraphState* GetState();
};

class BShkbAnimationGraph
{
public:
    GraphState* GetBehaviorState()
    {
        return !behavior ? nullptr : behavior->GetState();
    }

    bool Functionbcae00();

    std::uint8_t unk00[0xF0];
    GraphBehavior* behavior;
    std::uint8_t unkF8[0x140];
    void* unk238;
};
static_assert(offsetof(BShkbAnimationGraph, behavior) == 0xF0, "behavior offset");
static_assert(offsetof(BShkbAnimationGraph, unk238) == 0x238, "unk238 offset");
