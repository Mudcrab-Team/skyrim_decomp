// Source exposure: mixed (pinned community reference-count/movement-interface storage, independent target construction/RTTI/slot analysis).
// Code origin: original explicitly narrowed owner/interface views and defaulted construction, reusing the represented community-backed MovementAgent storage. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSIntrusiveRefCounted.h and include/RE/I/{IMovementInterface,IMovementState}.h; MIT.
// BSIntrusiveRefCounted, IMovementInterface, IMovementState, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MovementAgent, IPipelineStageInterface: EXE_RTTI
// MovementVptrContractLayout, Identity, all owner names ending InterfacePrefixLayout and their StorageLayout mirrors: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include "MovementAgentPathFollowerStandardPrefixLayout.h"
namespace ResearchLayouts {
template<unsigned Identity> class MovementVptrContractLayout {
public:
    virtual ~MovementVptrContractLayout();
};
static_assert(sizeof(MovementVptrContractLayout<0>) == 8, "represented vptr contract");
// MovementAgentActorAvoiderInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementAgentActorAvoider@@
// Contract0, offset24: .?AUIMovementPlannerAgent@@
// Contract1, offset32: .?AUIMovementPathManagerAgent@@
// Contract2, offset40: .?AVIMovementQueryActorAvoidance@@
class MovementAgentActorAvoiderInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<0>, public MovementVptrContractLayout<1>, public MovementVptrContractLayout<2> {
public:
    MovementAgentActorAvoiderInterfacePrefixLayout();
    ~MovementAgentActorAvoiderInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementAgentActorAvoiderInterfacePrefixLayout) == 48, "represented contiguous MovementAgent/interface prefix only");
struct MovementAgentActorAvoiderInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
};
static_assert(sizeof(MovementAgentActorAvoiderInterfacePrefixLayoutStorageLayout) == sizeof(MovementAgentActorAvoiderInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementAgentActorAvoiderInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementAgentActorAvoiderInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
static_assert(offsetof(MovementAgentActorAvoiderInterfacePrefixLayoutStorageLayout, interface2) == 40, "independent target subobject offset");
// MovementAgentActorStateInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementAgentActorState@@
// Contract3, offset24: .?AUIMovementPlannerAgent@@
// Contract4, offset32: .?AVIMovementSetState@@
// Contract5, offset40: .?AVIMovementQueryState@@
class MovementAgentActorStateInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<3>, public MovementVptrContractLayout<4>, public MovementVptrContractLayout<5> {
public:
    MovementAgentActorStateInterfacePrefixLayout();
    ~MovementAgentActorStateInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementAgentActorStateInterfacePrefixLayout) == 48, "represented contiguous MovementAgent/interface prefix only");
struct MovementAgentActorStateInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
};
static_assert(sizeof(MovementAgentActorStateInterfacePrefixLayoutStorageLayout) == sizeof(MovementAgentActorStateInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementAgentActorStateInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementAgentActorStateInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
static_assert(offsetof(MovementAgentActorStateInterfacePrefixLayoutStorageLayout, interface2) == 40, "independent target subobject offset");
// MovementAgentPathFollowerFlightInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementAgentPathFollowerFlight@@
// Contract6, offset24: .?AUIMovementPlannerAgent@@
// Contract7, offset32: .?AUIMovementPathManagerAgent@@
// Contract8, offset40: .?AVIMovementQueryPathFollowing@@
// Contract9, offset48: .?AVIMovementQueryFlight@@
class MovementAgentPathFollowerFlightInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<6>, public MovementVptrContractLayout<7>, public MovementVptrContractLayout<8>, public MovementVptrContractLayout<9> {
public:
    MovementAgentPathFollowerFlightInterfacePrefixLayout();
    ~MovementAgentPathFollowerFlightInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementAgentPathFollowerFlightInterfacePrefixLayout) == 56, "represented contiguous MovementAgent/interface prefix only");
struct MovementAgentPathFollowerFlightInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
    const void* const* interface3;
};
static_assert(sizeof(MovementAgentPathFollowerFlightInterfacePrefixLayoutStorageLayout) == sizeof(MovementAgentPathFollowerFlightInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementAgentPathFollowerFlightInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementAgentPathFollowerFlightInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
static_assert(offsetof(MovementAgentPathFollowerFlightInterfacePrefixLayoutStorageLayout, interface2) == 40, "independent target subobject offset");
static_assert(offsetof(MovementAgentPathFollowerFlightInterfacePrefixLayoutStorageLayout, interface3) == 48, "independent target subobject offset");
// MovementAgentPathFollowerVirtualInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementAgentPathFollowerVirtual@@
// Contract10, offset24: .?AUIMovementPlannerAgent@@
// Contract11, offset32: .?AUIMovementPathManagerAgent@@
// Contract12, offset40: .?AVIMovementQueryPathFollowing@@
// Contract13, offset48: .?AVIMovementSetPathFollowing@@
class MovementAgentPathFollowerVirtualInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<10>, public MovementVptrContractLayout<11>, public MovementVptrContractLayout<12>, public MovementVptrContractLayout<13> {
public:
    MovementAgentPathFollowerVirtualInterfacePrefixLayout();
    ~MovementAgentPathFollowerVirtualInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementAgentPathFollowerVirtualInterfacePrefixLayout) == 56, "represented contiguous MovementAgent/interface prefix only");
struct MovementAgentPathFollowerVirtualInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
    const void* const* interface3;
};
static_assert(sizeof(MovementAgentPathFollowerVirtualInterfacePrefixLayoutStorageLayout) == sizeof(MovementAgentPathFollowerVirtualInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementAgentPathFollowerVirtualInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementAgentPathFollowerVirtualInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
static_assert(offsetof(MovementAgentPathFollowerVirtualInterfacePrefixLayoutStorageLayout, interface2) == 40, "independent target subobject offset");
static_assert(offsetof(MovementAgentPathFollowerVirtualInterfacePrefixLayoutStorageLayout, interface3) == 48, "independent target subobject offset");
// MovementHandlerAgentInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgent@@
// Contract14, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<14> {
public:
    MovementHandlerAgentInterfacePrefixLayout();
    ~MovementHandlerAgentInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentAngleControllerInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentAngleController@@
// Contract15, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentAngleControllerInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<15> {
public:
    MovementHandlerAgentAngleControllerInterfacePrefixLayout();
    ~MovementHandlerAgentAngleControllerInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentAngleControllerInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentAngleControllerInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentAngleControllerInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentAngleControllerInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentAngleControllerInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentAngleGainInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentAngleGain@@
// Contract16, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentAngleGainInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<16> {
public:
    MovementHandlerAgentAngleGainInterfacePrefixLayout();
    ~MovementHandlerAgentAngleGainInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentAngleGainInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentAngleGainInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentAngleGainInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentAngleGainInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentAngleGainInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentAnglePassThroughInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentAnglePassThrough@@
// Contract17, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentAnglePassThroughInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<17> {
public:
    MovementHandlerAgentAnglePassThroughInterfacePrefixLayout();
    ~MovementHandlerAgentAnglePassThroughInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentAnglePassThroughInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentAnglePassThroughInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentAnglePassThroughInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentAnglePassThroughInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentAnglePassThroughInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentDirectControlInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentDirectControl@@
// Contract18, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentDirectControlInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<18> {
public:
    MovementHandlerAgentDirectControlInterfacePrefixLayout();
    ~MovementHandlerAgentDirectControlInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentDirectControlInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentDirectControlInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentDirectControlInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentDirectControlInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentDirectControlInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentDirectionPassThroughInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentDirectionPassThrough@@
// Contract19, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentDirectionPassThroughInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<19> {
public:
    MovementHandlerAgentDirectionPassThroughInterfacePrefixLayout();
    ~MovementHandlerAgentDirectionPassThroughInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentDirectionPassThroughInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentDirectionPassThroughInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentDirectionPassThroughInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentDirectionPassThroughInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentDirectionPassThroughInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentLargeDeltaIdle@@
// Contract20, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<20> {
public:
    MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayout();
    ~MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentPlayerControlsInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentPlayerControls@@
// Contract21, offset24: .?AUIMovementHandlerAgent@@
// Contract22, offset32: .?AUIMovementSetPlayerControls@@
class MovementHandlerAgentPlayerControlsInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<21>, public MovementVptrContractLayout<22> {
public:
    MovementHandlerAgentPlayerControlsInterfacePrefixLayout();
    ~MovementHandlerAgentPlayerControlsInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentPlayerControlsInterfacePrefixLayout) == 40, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentPlayerControlsInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
};
static_assert(sizeof(MovementHandlerAgentPlayerControlsInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentPlayerControlsInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentPlayerControlsInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementHandlerAgentPlayerControlsInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
// MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentPlayerControlsActionTrigger@@
// Contract23, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<23> {
public:
    MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayout();
    ~MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentSpeedPassThroughInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentSpeedPassThrough@@
// Contract24, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentSpeedPassThroughInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<24> {
public:
    MovementHandlerAgentSpeedPassThroughInterfacePrefixLayout();
    ~MovementHandlerAgentSpeedPassThroughInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentSpeedPassThroughInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentSpeedPassThroughInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentSpeedPassThroughInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentSpeedPassThroughInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentSpeedPassThroughInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentSprintActionTriggerInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentSprintActionTrigger@@
// Contract25, offset24: .?AUIMovementHandlerAgent@@
// Contract26, offset32: .?AVIMovementSetSprinting@@
class MovementHandlerAgentSprintActionTriggerInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<25>, public MovementVptrContractLayout<26> {
public:
    MovementHandlerAgentSprintActionTriggerInterfacePrefixLayout();
    ~MovementHandlerAgentSprintActionTriggerInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentSprintActionTriggerInterfacePrefixLayout) == 40, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentSprintActionTriggerInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
};
static_assert(sizeof(MovementHandlerAgentSprintActionTriggerInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentSprintActionTriggerInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentSprintActionTriggerInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementHandlerAgentSprintActionTriggerInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
// MovementHandlerAgentStairsHelperInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentStairsHelper@@
// Contract27, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentStairsHelperInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<27> {
public:
    MovementHandlerAgentStairsHelperInterfacePrefixLayout();
    ~MovementHandlerAgentStairsHelperInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentStairsHelperInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentStairsHelperInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentStairsHelperInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentStairsHelperInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentStairsHelperInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentStrafingInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentStrafing@@
// Contract28, offset24: .?AUIMovementHandlerAgent@@
class MovementHandlerAgentStrafingInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<28> {
public:
    MovementHandlerAgentStrafingInterfacePrefixLayout();
    ~MovementHandlerAgentStrafingInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentStrafingInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentStrafingInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementHandlerAgentStrafingInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentStrafingInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentStrafingInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementHandlerAgentTranslationControllerInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementHandlerAgentTranslationController@@
// Contract29, offset24: .?AUIMovementHandlerAgent@@
// Contract30, offset32: .?AUIMovementSetTranslationControllerType@@
class MovementHandlerAgentTranslationControllerInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<29>, public MovementVptrContractLayout<30> {
public:
    MovementHandlerAgentTranslationControllerInterfacePrefixLayout();
    ~MovementHandlerAgentTranslationControllerInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementHandlerAgentTranslationControllerInterfacePrefixLayout) == 40, "represented contiguous MovementAgent/interface prefix only");
struct MovementHandlerAgentTranslationControllerInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
};
static_assert(sizeof(MovementHandlerAgentTranslationControllerInterfacePrefixLayoutStorageLayout) == sizeof(MovementHandlerAgentTranslationControllerInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementHandlerAgentTranslationControllerInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementHandlerAgentTranslationControllerInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
// MovementPathManagerAgentInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPathManagerAgent@@
// Contract31, offset24: .?AUIMovementPathManagerAgent@@
class MovementPathManagerAgentInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<31> {
public:
    MovementPathManagerAgentInterfacePrefixLayout();
    ~MovementPathManagerAgentInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPathManagerAgentInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementPathManagerAgentInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementPathManagerAgentInterfacePrefixLayoutStorageLayout) == sizeof(MovementPathManagerAgentInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPathManagerAgentInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementPathManagerAgentAvoidBoxInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPathManagerAgentAvoidBox@@
// Contract32, offset24: .?AUIMovementPathManagerAgent@@
class MovementPathManagerAgentAvoidBoxInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<32> {
public:
    MovementPathManagerAgentAvoidBoxInterfacePrefixLayout();
    ~MovementPathManagerAgentAvoidBoxInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPathManagerAgentAvoidBoxInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementPathManagerAgentAvoidBoxInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementPathManagerAgentAvoidBoxInterfacePrefixLayoutStorageLayout) == sizeof(MovementPathManagerAgentAvoidBoxInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPathManagerAgentAvoidBoxInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPathManagerAgentLoadedAreaMonitor@@
// Contract33, offset24: .?AUIMovementPathManagerAgent@@
class MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<33> {
public:
    MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayout();
    ~MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayoutStorageLayout) == sizeof(MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementPathManagerAgentStaticAvoiderInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPathManagerAgentStaticAvoider@@
// Contract34, offset24: .?AUIMovementPathManagerAgent@@
// Contract35, offset32: .?AVIMovementQueryStaticAvoider@@
// Contract36, offset40: .?AVIMovementSetStaticAvoider@@
class MovementPathManagerAgentStaticAvoiderInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<34>, public MovementVptrContractLayout<35>, public MovementVptrContractLayout<36> {
public:
    MovementPathManagerAgentStaticAvoiderInterfacePrefixLayout();
    ~MovementPathManagerAgentStaticAvoiderInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPathManagerAgentStaticAvoiderInterfacePrefixLayout) == 48, "represented contiguous MovementAgent/interface prefix only");
struct MovementPathManagerAgentStaticAvoiderInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
};
static_assert(sizeof(MovementPathManagerAgentStaticAvoiderInterfacePrefixLayoutStorageLayout) == sizeof(MovementPathManagerAgentStaticAvoiderInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPathManagerAgentStaticAvoiderInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementPathManagerAgentStaticAvoiderInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
static_assert(offsetof(MovementPathManagerAgentStaticAvoiderInterfacePrefixLayoutStorageLayout, interface2) == 40, "independent target subobject offset");
// MovementPlannerAgentInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPlannerAgent@@
// Contract37, offset24: .?AUIMovementPlannerAgent@@
class MovementPlannerAgentInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<37> {
public:
    MovementPlannerAgentInterfacePrefixLayout();
    ~MovementPlannerAgentInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPlannerAgentInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementPlannerAgentInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementPlannerAgentInterfacePrefixLayoutStorageLayout) == sizeof(MovementPlannerAgentInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPlannerAgentInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementPlannerAgentDirectControlInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPlannerAgentDirectControl@@
// Contract38, offset24: .?AUIMovementPlannerAgent@@
class MovementPlannerAgentDirectControlInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<38> {
public:
    MovementPlannerAgentDirectControlInterfacePrefixLayout();
    ~MovementPlannerAgentDirectControlInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPlannerAgentDirectControlInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementPlannerAgentDirectControlInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementPlannerAgentDirectControlInterfacePrefixLayoutStorageLayout) == sizeof(MovementPlannerAgentDirectControlInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPlannerAgentDirectControlInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementPlannerAgentHorseControlsInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPlannerAgentHorseControls@@
// Contract39, offset24: .?AUIMovementPlannerAgent@@
class MovementPlannerAgentHorseControlsInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<39> {
public:
    MovementPlannerAgentHorseControlsInterfacePrefixLayout();
    ~MovementPlannerAgentHorseControlsInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPlannerAgentHorseControlsInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementPlannerAgentHorseControlsInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementPlannerAgentHorseControlsInterfacePrefixLayoutStorageLayout) == sizeof(MovementPlannerAgentHorseControlsInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPlannerAgentHorseControlsInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementPlannerAgentKeepOffsetInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPlannerAgentKeepOffset@@
// Contract40, offset24: .?AUIMovementPlannerAgent@@
// Contract41, offset32: .?AUIMovementSetKeepOffsetFromActor@@
class MovementPlannerAgentKeepOffsetInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<40>, public MovementVptrContractLayout<41> {
public:
    MovementPlannerAgentKeepOffsetInterfacePrefixLayout();
    ~MovementPlannerAgentKeepOffsetInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPlannerAgentKeepOffsetInterfacePrefixLayout) == 40, "represented contiguous MovementAgent/interface prefix only");
struct MovementPlannerAgentKeepOffsetInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
};
static_assert(sizeof(MovementPlannerAgentKeepOffsetInterfacePrefixLayoutStorageLayout) == sizeof(MovementPlannerAgentKeepOffsetInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPlannerAgentKeepOffsetInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementPlannerAgentKeepOffsetInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
// MovementPlannerAgentNavmeshBoundsInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPlannerAgentNavmeshBounds@@
// Contract42, offset24: .?AUIMovementPlannerAgent@@
// Contract43, offset32: .?AUIMovementPathManagerAgent@@
class MovementPlannerAgentNavmeshBoundsInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<42>, public MovementVptrContractLayout<43> {
public:
    MovementPlannerAgentNavmeshBoundsInterfacePrefixLayout();
    ~MovementPlannerAgentNavmeshBoundsInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPlannerAgentNavmeshBoundsInterfacePrefixLayout) == 40, "represented contiguous MovementAgent/interface prefix only");
struct MovementPlannerAgentNavmeshBoundsInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
};
static_assert(sizeof(MovementPlannerAgentNavmeshBoundsInterfacePrefixLayoutStorageLayout) == sizeof(MovementPlannerAgentNavmeshBoundsInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPlannerAgentNavmeshBoundsInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementPlannerAgentNavmeshBoundsInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
// MovementPlannerAgentWarpInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementPlannerAgentWarp@@
// Contract44, offset24: .?AUIMovementPlannerAgent@@
// Contract45, offset32: .?AUIMovementSetWarp@@
class MovementPlannerAgentWarpInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<44>, public MovementVptrContractLayout<45> {
public:
    MovementPlannerAgentWarpInterfacePrefixLayout();
    ~MovementPlannerAgentWarpInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementPlannerAgentWarpInterfacePrefixLayout) == 40, "represented contiguous MovementAgent/interface prefix only");
struct MovementPlannerAgentWarpInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
};
static_assert(sizeof(MovementPlannerAgentWarpInterfacePrefixLayoutStorageLayout) == sizeof(MovementPlannerAgentWarpInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementPlannerAgentWarpInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementPlannerAgentWarpInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
// MovementStateFollowPathInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementStateFollowPath@@
// Contract46, offset24: .?AUIMovementState@@
class MovementStateFollowPathInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<46> {
public:
    MovementStateFollowPathInterfacePrefixLayout();
    ~MovementStateFollowPathInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementStateFollowPathInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementStateFollowPathInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementStateFollowPathInterfacePrefixLayoutStorageLayout) == sizeof(MovementStateFollowPathInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementStateFollowPathInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementStateTweenerInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementStateTweener@@
// Contract47, offset24: .?AUIMovementState@@
class MovementStateTweenerInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<47> {
public:
    MovementStateTweenerInterfacePrefixLayout();
    ~MovementStateTweenerInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementStateTweenerInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementStateTweenerInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementStateTweenerInterfacePrefixLayoutStorageLayout) == sizeof(MovementStateTweenerInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementStateTweenerInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementTweenerAgentInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementTweenerAgent@@
// Contract48, offset24: .?AUIMovementTweenerAgent@@
class MovementTweenerAgentInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<48> {
public:
    MovementTweenerAgentInterfacePrefixLayout();
    ~MovementTweenerAgentInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementTweenerAgentInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementTweenerAgentInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementTweenerAgentInterfacePrefixLayoutStorageLayout) == sizeof(MovementTweenerAgentInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementTweenerAgentInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementTweenerAgentAnimationDrivenInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementTweenerAgentAnimationDriven@@
// Contract49, offset24: .?AUIMovementTweenerAgent@@
class MovementTweenerAgentAnimationDrivenInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<49> {
public:
    MovementTweenerAgentAnimationDrivenInterfacePrefixLayout();
    ~MovementTweenerAgentAnimationDrivenInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementTweenerAgentAnimationDrivenInterfacePrefixLayout) == 32, "represented contiguous MovementAgent/interface prefix only");
struct MovementTweenerAgentAnimationDrivenInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
};
static_assert(sizeof(MovementTweenerAgentAnimationDrivenInterfacePrefixLayoutStorageLayout) == sizeof(MovementTweenerAgentAnimationDrivenInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementTweenerAgentAnimationDrivenInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
// MovementTweenerAgentFixedDeltaInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementTweenerAgentFixedDelta@@
// Contract50, offset24: .?AUIMovementTweenerAgent@@
// Contract51, offset32: .?AUIMovementSetCorrectionData@@
class MovementTweenerAgentFixedDeltaInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<50>, public MovementVptrContractLayout<51> {
public:
    MovementTweenerAgentFixedDeltaInterfacePrefixLayout();
    ~MovementTweenerAgentFixedDeltaInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementTweenerAgentFixedDeltaInterfacePrefixLayout) == 40, "represented contiguous MovementAgent/interface prefix only");
struct MovementTweenerAgentFixedDeltaInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
};
static_assert(sizeof(MovementTweenerAgentFixedDeltaInterfacePrefixLayoutStorageLayout) == sizeof(MovementTweenerAgentFixedDeltaInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementTweenerAgentFixedDeltaInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementTweenerAgentFixedDeltaInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
// MovementTweenerAgentNodeFollowerInterfacePrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVMovementTweenerAgentNodeFollower@@
// Contract52, offset24: .?AUIMovementTweenerAgent@@
// Contract53, offset32: .?AVITweenerNodeFollowerSetup@@
class MovementTweenerAgentNodeFollowerInterfacePrefixLayout : public MovementAgentStoragePrefixLayout, public MovementVptrContractLayout<52>, public MovementVptrContractLayout<53> {
public:
    MovementTweenerAgentNodeFollowerInterfacePrefixLayout();
    ~MovementTweenerAgentNodeFollowerInterfacePrefixLayout() override;
};
static_assert(sizeof(MovementTweenerAgentNodeFollowerInterfacePrefixLayout) == 40, "represented contiguous MovementAgent/interface prefix only");
struct MovementTweenerAgentNodeFollowerInterfacePrefixLayoutStorageLayout {
    MovementAgentStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
};
static_assert(sizeof(MovementTweenerAgentNodeFollowerInterfacePrefixLayoutStorageLayout) == sizeof(MovementTweenerAgentNodeFollowerInterfacePrefixLayout), "physical prefix mirror");
static_assert(offsetof(MovementTweenerAgentNodeFollowerInterfacePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(MovementTweenerAgentNodeFollowerInterfacePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
}
