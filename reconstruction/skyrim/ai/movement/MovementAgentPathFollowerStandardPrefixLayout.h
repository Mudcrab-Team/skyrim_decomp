// Source exposure: mixed (pinned community intrusive-reference and movement-interface declarations; independent target RTTI/construction/slot analysis).
// Code origin: adapted field/interface declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSIntrusiveRefCounted.h and include/RE/I/{IMovementInterface,IMovementState}.h; MIT.
// BSIntrusiveRefCounted, _refCount, IMovementInterface, IMovementState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MovementAgent, MovementAgentPathFollowerStandard, IPipelineStageInterface, IMovementPlannerAgent, IMovementPathManagerAgent, IMovementQueryPathFollowing, IMovementSetPathFollowing, IMovementPlayIdleResult, IMovementHandlerAgent, NullMovementState: EXE_RTTI
// MovementAgentStoragePrefixLayout, MovementInterfacePrefixLayout, MovementStatePrefixLayout, PipelineStagePrefixLayout, MovementPlannerPrefixLayout, MovementPathManagerPrefixLayout, MovementQueryPathFollowingPrefixLayout, MovementSetPathFollowingPrefixLayout, MovementIdleResultPrefixLayout, MovementHandlerPrefixLayout, MovementAgentPathFollowerStandardPrefixLayout, MovementAgentPathFollowerStandardPrefixStorageLayout, state: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "bscore/BSIntrusiveRefCountedStorageLayout.h"
namespace ResearchLayouts {
class MovementInterfacePrefixLayout { public: virtual ~MovementInterfacePrefixLayout(); };
class MovementStatePrefixLayout : public MovementInterfacePrefixLayout { public: ~MovementStatePrefixLayout() override; };
class MovementAgentStoragePrefixLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~MovementAgentStoragePrefixLayout();
    MovementStatePrefixLayout* state;
};
class PipelineStagePrefixLayout { public: virtual ~PipelineStagePrefixLayout(); };
class MovementPlannerPrefixLayout : public PipelineStagePrefixLayout { public: ~MovementPlannerPrefixLayout() override; };
class MovementPathManagerPrefixLayout : public PipelineStagePrefixLayout { public: ~MovementPathManagerPrefixLayout() override; };
class MovementQueryPathFollowingPrefixLayout : public MovementInterfacePrefixLayout { public: ~MovementQueryPathFollowingPrefixLayout() override; };
class MovementSetPathFollowingPrefixLayout : public MovementInterfacePrefixLayout { public: ~MovementSetPathFollowingPrefixLayout() override; };
class MovementIdleResultPrefixLayout { public: virtual ~MovementIdleResultPrefixLayout(); };
class MovementHandlerPrefixLayout : public PipelineStagePrefixLayout { public: ~MovementHandlerPrefixLayout() override; };
class MovementAgentPathFollowerStandardPrefixLayout : public MovementAgentStoragePrefixLayout, public MovementPlannerPrefixLayout, public MovementPathManagerPrefixLayout, public MovementQueryPathFollowingPrefixLayout, public MovementSetPathFollowingPrefixLayout, public MovementIdleResultPrefixLayout, public MovementHandlerPrefixLayout {
public:
    MovementAgentPathFollowerStandardPrefixLayout();
    ~MovementAgentPathFollowerStandardPrefixLayout() override;
};
struct MovementAgentPathFollowerStandardPrefixStorageLayout {
    const void* const* primary;
    volatile std::uint32_t refCount;
    MovementStatePrefixLayout* state;
    const void* const* planner;
    const void* const* pathManager;
    const void* const* queryPath;
    const void* const* setPath;
    const void* const* idleResult;
    const void* const* handler;
};
static_assert(sizeof(MovementInterfacePrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementStatePrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementAgentStoragePrefixLayout) == 24, "represented observed storage/interface prefix");
static_assert(sizeof(PipelineStagePrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementPlannerPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementPathManagerPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementQueryPathFollowingPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementSetPathFollowingPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementIdleResultPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementHandlerPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementAgentPathFollowerStandardPrefixLayout) == 72, "represented observed storage/interface prefix");
static_assert(sizeof(MovementAgentPathFollowerStandardPrefixStorageLayout) == 72, "represented observed storage/interface prefix");
static_assert(offsetof(MovementAgentStoragePrefixLayout, _refCount) == 8, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentStoragePrefixLayout, state) == 16, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, primary) == 0, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, refCount) == 8, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, state) == 16, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, planner) == 24, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, pathManager) == 32, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, queryPath) == 40, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, setPath) == 48, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, idleResult) == 56, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, handler) == 64, "independent target field/subobject offset");
}
