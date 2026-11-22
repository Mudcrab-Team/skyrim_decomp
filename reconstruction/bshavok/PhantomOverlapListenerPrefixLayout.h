// Source exposure: mixed (pinned community storage, permitted FNV interface declaration, independent target RTTI/slot analysis).
// Code origin: adapted public storage and permitted sibling interface declarations, original narrowed prefix construction. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BGSIdleCollection.h,T/TESReactionForm.h,B/BSTList.h,T/TESLeveledList.h,T/TESAttackDamageForm.h,T/TESChildCell.h,H/hkpContactListener.h}; MIT.
// BGSIdleCollection, TESReactionForm, BSSimpleList, TESLeveledList, TESAttackDamageForm, TESChildCell, hkpContactListener: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// hkpPhantomOverlapListener: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 include/hkpPhantomOverlapListener.h:3
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, and physical mirror member names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "bscore/AdditionalInterfacePrefixLayout.h"
namespace ResearchLayouts {
class IdleFormPointeeLayout;
class ReactionEntryPointeeLayout;
class LeveledEntryPointeeLayout;
class GlobalPointeeLayout;
class ContactPointEventPointeeLayout;
class CollisionEventPointeeLayout;
struct ReactionListStorageLayout {
    ReactionEntryPointeeLayout* item;
    ReactionListStorageLayout* next;
};
class IdleCollectionPrefixLayout : public FormComponentLayout {
public:
    ~IdleCollectionPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    std::int8_t idleFlags;
    std::int8_t idleCount;
    IdleFormPointeeLayout** idles;
    float timerCheckForIdle;
};
class ReactionComponentPrefixLayout : public FormComponentLayout {
public:
    ~ReactionComponentPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    ReactionListStorageLayout reactions;
    std::uint8_t groupFormType;
};
class LeveledListComponentPrefixLayout : public FormComponentLayout {
public:
    ~LeveledListComponentPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    LeveledEntryPointeeLayout* entries;
    std::int8_t chanceNone;
    std::uint8_t llFlags;
    std::uint8_t numEntries;
    std::uint8_t unk13;
    void* unk18;
    GlobalPointeeLayout* chanceGlobal;
};
class AttackDamageComponentPrefixLayout : public FormComponentLayout {
public:
    ~AttackDamageComponentPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    std::uint16_t attackDamage;
};
class PhantomOverlapListenerPrefixLayout {
public:
    virtual void vf00();
    virtual void vf01();
    virtual ~PhantomOverlapListenerPrefixLayout();
};
class ContactListenerPrefixLayout {
public:
    virtual void ContactPointCallback(const ContactPointEventPointeeLayout&);
    virtual void CollisionAddedCallback(const CollisionEventPointeeLayout&);
    virtual void CollisionRemovedCallback(const CollisionEventPointeeLayout&);
    virtual ~ContactListenerPrefixLayout();
};
static_assert(sizeof(ReactionListStorageLayout) == 16, "public inline list-head storage");
static_assert(offsetof(ReactionListStorageLayout, next) == 8, "public list next pointer");
static_assert(sizeof(IdleCollectionPrefixLayout) == 32, "public idle component storage");
static_assert(offsetof(IdleCollectionPrefixLayout, idleFlags) == 8, "public idle flags offset");
static_assert(offsetof(IdleCollectionPrefixLayout, idleCount) == 9, "public idle count offset");
static_assert(offsetof(IdleCollectionPrefixLayout, idles) == 16, "public idle pointer offset");
static_assert(offsetof(IdleCollectionPrefixLayout, timerCheckForIdle) == 24, "public idle timer offset");
static_assert(sizeof(ReactionComponentPrefixLayout) == 32, "public reaction component storage");
static_assert(offsetof(ReactionComponentPrefixLayout, reactions) == 8, "public inline list offset");
static_assert(offsetof(ReactionComponentPrefixLayout, groupFormType) == 24, "public group type offset");
static_assert(sizeof(LeveledListComponentPrefixLayout) == 40, "public leveled list storage");
static_assert(offsetof(LeveledListComponentPrefixLayout, entries) == 8, "public entries pointer storage offset");
static_assert(offsetof(LeveledListComponentPrefixLayout, chanceNone) == 16, "public chance offset");
static_assert(offsetof(LeveledListComponentPrefixLayout, llFlags) == 17, "public flags offset");
static_assert(offsetof(LeveledListComponentPrefixLayout, numEntries) == 18, "public entry count offset");
static_assert(offsetof(LeveledListComponentPrefixLayout, unk13) == 19, "public unknown byte offset");
static_assert(offsetof(LeveledListComponentPrefixLayout, unk18) == 24, "public unknown pointer offset");
static_assert(offsetof(LeveledListComponentPrefixLayout, chanceGlobal) == 32, "public global chance pointer offset");
static_assert(sizeof(AttackDamageComponentPrefixLayout) == 16, "public attack component storage");
static_assert(offsetof(AttackDamageComponentPrefixLayout, attackDamage) == 8, "public attack damage offset");
static_assert(sizeof(PhantomOverlapListenerPrefixLayout) == 8, "permitted fieldless interface storage");
static_assert(sizeof(ContactListenerPrefixLayout) == 8, "public fieldless contact interface storage");
// BGSIdleMarker: EXE_RTTI
// Owner descriptor: .?AVBGSIdleMarker@@
// Represented subobject at0: public form primary
// Represented subobject at48: .?AVTESModel@@
// Represented subobject at88: .?AVBGSIdleCollection@@
class BGSIdleMarkerRemainingStoragePrefixLayout : public BoundObjectFormHeaderLayout, public ModelComponentLayout, public IdleCollectionPrefixLayout {
public:
    BGSIdleMarkerRemainingStoragePrefixLayout();
    ~BGSIdleMarkerRemainingStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSIdleMarkerRemainingStoragePrefixLayout) == 120, "represented initial prefix only");
struct BGSIdleMarkerRemainingStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    ModelComponentLayout component1;
    IdleCollectionPrefixLayout component2;
};
static_assert(sizeof(BGSIdleMarkerRemainingStoragePrefixLayoutStorageLayout) == 120, "physical prefix mirror");
static_assert(offsetof(BGSIdleMarkerRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(BGSIdleMarkerRemainingStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(BGSIdleMarkerRemainingStoragePrefixLayoutStorageLayout, component2) == 88, "independent target subobject offset");
// TESFaction: EXE_RTTI
// Owner descriptor: .?AVTESFaction@@
// Represented subobject at0: public form primary
// Represented subobject at32: .?AVTESFullName@@
// Represented subobject at48: .?AVTESReactionForm@@
class TESFactionRemainingStoragePrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public ReactionComponentPrefixLayout {
public:
    TESFactionRemainingStoragePrefixLayout();
    ~TESFactionRemainingStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESFactionRemainingStoragePrefixLayout) == 80, "represented initial prefix only");
struct TESFactionRemainingStoragePrefixLayoutStorageLayout {
    FormHeaderLayout component0;
    FullNameComponentLayout component1;
    ReactionComponentPrefixLayout component2;
};
static_assert(sizeof(TESFactionRemainingStoragePrefixLayoutStorageLayout) == 80, "physical prefix mirror");
static_assert(offsetof(TESFactionRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESFactionRemainingStoragePrefixLayoutStorageLayout, component1) == 32, "independent target subobject offset");
static_assert(offsetof(TESFactionRemainingStoragePrefixLayoutStorageLayout, component2) == 48, "independent target subobject offset");
// TESLevCharacter: EXE_RTTI
// Owner descriptor: .?AVTESLevCharacter@@
// Represented subobject at0: public form primary
// Represented subobject at48: .?AVTESLeveledList@@
// Represented subobject at88: .?AVTESModelTextureSwap@@
class TESLevCharacterRemainingStoragePrefixLayout : public BoundObjectFormHeaderLayout, public LeveledListComponentPrefixLayout, public ModelTextureSwapComponentLayout {
public:
    TESLevCharacterRemainingStoragePrefixLayout();
    ~TESLevCharacterRemainingStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESLevCharacterRemainingStoragePrefixLayout) == 144, "represented initial prefix only");
struct TESLevCharacterRemainingStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    LeveledListComponentPrefixLayout component1;
    ModelTextureSwapComponentLayout component2;
};
static_assert(sizeof(TESLevCharacterRemainingStoragePrefixLayoutStorageLayout) == 144, "physical prefix mirror");
static_assert(offsetof(TESLevCharacterRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESLevCharacterRemainingStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(TESLevCharacterRemainingStoragePrefixLayoutStorageLayout, component2) == 88, "independent target subobject offset");
// TESObjectLAND: EXE_RTTI
// Owner descriptor: .?AVTESObjectLAND@@
// Represented subobject at0: public form primary
// Represented subobject at32: .?AVTESChildCell@@
class TESObjectLANDRemainingStoragePrefixLayout : public FormHeaderLayout, public AdditionalInterfacePrefixLayout<2000> {
public:
    TESObjectLANDRemainingStoragePrefixLayout();
    ~TESObjectLANDRemainingStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectLANDRemainingStoragePrefixLayout) == 40, "represented initial prefix only");
struct TESObjectLANDRemainingStoragePrefixLayoutStorageLayout {
    FormHeaderLayout component0;
    AdditionalInterfacePrefixLayout<2000> component1;
};
static_assert(sizeof(TESObjectLANDRemainingStoragePrefixLayoutStorageLayout) == 40, "physical prefix mirror");
static_assert(offsetof(TESObjectLANDRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESObjectLANDRemainingStoragePrefixLayoutStorageLayout, component1) == 32, "independent target subobject offset");
// TESWaterForm: EXE_RTTI
// Owner descriptor: .?AVTESWaterForm@@
// Represented subobject at0: public form primary
// Represented subobject at32: .?AVTESFullName@@
// Represented subobject at48: .?AVTESAttackDamageForm@@
class TESWaterFormRemainingStoragePrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public AttackDamageComponentPrefixLayout {
public:
    TESWaterFormRemainingStoragePrefixLayout();
    ~TESWaterFormRemainingStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESWaterFormRemainingStoragePrefixLayout) == 64, "represented initial prefix only");
struct TESWaterFormRemainingStoragePrefixLayoutStorageLayout {
    FormHeaderLayout component0;
    FullNameComponentLayout component1;
    AttackDamageComponentPrefixLayout component2;
};
static_assert(sizeof(TESWaterFormRemainingStoragePrefixLayoutStorageLayout) == 64, "physical prefix mirror");
static_assert(offsetof(TESWaterFormRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESWaterFormRemainingStoragePrefixLayoutStorageLayout, component1) == 32, "independent target subobject offset");
static_assert(offsetof(TESWaterFormRemainingStoragePrefixLayoutStorageLayout, component2) == 48, "independent target subobject offset");
// TESWorldSpace: EXE_RTTI
// Owner descriptor: .?AVTESWorldSpace@@
// Represented subobject at0: public form primary
// Represented subobject at32: .?AVTESFullName@@
// Represented subobject at48: .?AVTESModel@@
class TESWorldSpaceRemainingStoragePrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public ModelComponentLayout {
public:
    TESWorldSpaceRemainingStoragePrefixLayout();
    ~TESWorldSpaceRemainingStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESWorldSpaceRemainingStoragePrefixLayout) == 88, "represented initial prefix only");
struct TESWorldSpaceRemainingStoragePrefixLayoutStorageLayout {
    FormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelComponentLayout component2;
};
static_assert(sizeof(TESWorldSpaceRemainingStoragePrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(TESWorldSpaceRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESWorldSpaceRemainingStoragePrefixLayoutStorageLayout, component1) == 32, "independent target subobject offset");
static_assert(offsetof(TESWorldSpaceRemainingStoragePrefixLayoutStorageLayout, component2) == 48, "independent target subobject offset");
// hkCpuWorldGetClosestPointsCollector: EXE_RTTI
// Owner descriptor: .?AVhkCpuWorldGetClosestPointsCollector@@
// Represented subobject at0: .?AVhkpBroadPhaseCastCollector@@
// Represented subobject at8: .?AUCollector@?$hkAabbTreeQueryUtils@UhkAabbTreeAabb16@hkAabbTreeData@@G@@
// Represented subobject at16: .?AVhkKdTreeCastCollector@@
class hkCpuWorldGetClosestPointsCollectorRemainingStoragePrefixLayout : public AdditionalInterfacePrefixLayout<2001>, public AdditionalInterfacePrefixLayout<2002>, public AdditionalInterfacePrefixLayout<2003> {
public:
    hkCpuWorldGetClosestPointsCollectorRemainingStoragePrefixLayout();
    ~hkCpuWorldGetClosestPointsCollectorRemainingStoragePrefixLayout() override;
};
static_assert(sizeof(hkCpuWorldGetClosestPointsCollectorRemainingStoragePrefixLayout) == 24, "represented initial prefix only");
struct hkCpuWorldGetClosestPointsCollectorRemainingStoragePrefixLayoutStorageLayout {
    AdditionalInterfacePrefixLayout<2001> component0;
    AdditionalInterfacePrefixLayout<2002> component1;
    AdditionalInterfacePrefixLayout<2003> component2;
};
static_assert(sizeof(hkCpuWorldGetClosestPointsCollectorRemainingStoragePrefixLayoutStorageLayout) == 24, "physical prefix mirror");
static_assert(offsetof(hkCpuWorldGetClosestPointsCollectorRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(hkCpuWorldGetClosestPointsCollectorRemainingStoragePrefixLayoutStorageLayout, component1) == 8, "independent target subobject offset");
static_assert(offsetof(hkCpuWorldGetClosestPointsCollectorRemainingStoragePrefixLayoutStorageLayout, component2) == 16, "independent target subobject offset");
// hkpBroadPhaseBorder: EXE_RTTI
// Owner descriptor: .?AVhkpBroadPhaseBorder@@
// Represented subobject at0: .?AVhkReferencedObject@@
// Represented subobject at16: .?AVhkpWorldDeletionListener@@
// Represented subobject at24: .?AVhkpPhantomOverlapListener@@
// Represented subobject at32: .?AVhkpWorldPostSimulationListener@@
class hkpBroadPhaseBorderRemainingStoragePrefixLayout : public HavokReferencePrefixLayout, public AdditionalInterfacePrefixLayout<2004>, public PhantomOverlapListenerPrefixLayout, public AdditionalInterfacePrefixLayout<2005> {
public:
    hkpBroadPhaseBorderRemainingStoragePrefixLayout();
    ~hkpBroadPhaseBorderRemainingStoragePrefixLayout() override;
};
static_assert(sizeof(hkpBroadPhaseBorderRemainingStoragePrefixLayout) == 40, "represented initial prefix only");
struct hkpBroadPhaseBorderRemainingStoragePrefixLayoutStorageLayout {
    HavokReferencePrefixLayout component0;
    AdditionalInterfacePrefixLayout<2004> component1;
    PhantomOverlapListenerPrefixLayout component2;
    AdditionalInterfacePrefixLayout<2005> component3;
};
static_assert(sizeof(hkpBroadPhaseBorderRemainingStoragePrefixLayoutStorageLayout) == 40, "physical prefix mirror");
static_assert(offsetof(hkpBroadPhaseBorderRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(hkpBroadPhaseBorderRemainingStoragePrefixLayoutStorageLayout, component1) == 16, "independent target subobject offset");
static_assert(offsetof(hkpBroadPhaseBorderRemainingStoragePrefixLayoutStorageLayout, component2) == 24, "independent target subobject offset");
static_assert(offsetof(hkpBroadPhaseBorderRemainingStoragePrefixLayoutStorageLayout, component3) == 32, "independent target subobject offset");
// hkpCharacterProxy: EXE_RTTI
// Owner descriptor: .?AVhkpCharacterProxy@@
// Represented subobject at0: .?AVhkReferencedObject@@
// Represented subobject at16: .?AVhkpEntityListener@@
// Represented subobject at24: .?AVhkpPhantomListener@@
class hkpCharacterProxyRemainingStoragePrefixLayout : public HavokReferencePrefixLayout, public AdditionalInterfacePrefixLayout<2006>, public AdditionalInterfacePrefixLayout<2007> {
public:
    hkpCharacterProxyRemainingStoragePrefixLayout();
    ~hkpCharacterProxyRemainingStoragePrefixLayout() override;
};
static_assert(sizeof(hkpCharacterProxyRemainingStoragePrefixLayout) == 32, "represented initial prefix only");
struct hkpCharacterProxyRemainingStoragePrefixLayoutStorageLayout {
    HavokReferencePrefixLayout component0;
    AdditionalInterfacePrefixLayout<2006> component1;
    AdditionalInterfacePrefixLayout<2007> component2;
};
static_assert(sizeof(hkpCharacterProxyRemainingStoragePrefixLayoutStorageLayout) == 32, "physical prefix mirror");
static_assert(offsetof(hkpCharacterProxyRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(hkpCharacterProxyRemainingStoragePrefixLayoutStorageLayout, component1) == 16, "independent target subobject offset");
static_assert(offsetof(hkpCharacterProxyRemainingStoragePrefixLayoutStorageLayout, component2) == 24, "independent target subobject offset");
// hkpCharacterRigidBody: EXE_RTTI
// Owner descriptor: .?AVhkpCharacterRigidBody@@
// Represented subobject at0: .?AVhkReferencedObject@@
// Represented subobject at16: .?AVhkpEntityListener@@
// Represented subobject at24: .?AVhkpWorldPostSimulationListener@@
class hkpCharacterRigidBodyRemainingStoragePrefixLayout : public HavokReferencePrefixLayout, public AdditionalInterfacePrefixLayout<2008>, public AdditionalInterfacePrefixLayout<2009> {
public:
    hkpCharacterRigidBodyRemainingStoragePrefixLayout();
    ~hkpCharacterRigidBodyRemainingStoragePrefixLayout() override;
};
static_assert(sizeof(hkpCharacterRigidBodyRemainingStoragePrefixLayout) == 32, "represented initial prefix only");
struct hkpCharacterRigidBodyRemainingStoragePrefixLayoutStorageLayout {
    HavokReferencePrefixLayout component0;
    AdditionalInterfacePrefixLayout<2008> component1;
    AdditionalInterfacePrefixLayout<2009> component2;
};
static_assert(sizeof(hkpCharacterRigidBodyRemainingStoragePrefixLayoutStorageLayout) == 32, "physical prefix mirror");
static_assert(offsetof(hkpCharacterRigidBodyRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(hkpCharacterRigidBodyRemainingStoragePrefixLayoutStorageLayout, component1) == 16, "independent target subobject offset");
static_assert(offsetof(hkpCharacterRigidBodyRemainingStoragePrefixLayoutStorageLayout, component2) == 24, "independent target subobject offset");
// hkpSuspendInactiveAgentsUtil: EXE_RTTI
// Owner descriptor: .?AVhkpSuspendInactiveAgentsUtil@@
// Represented subobject at0: .?AVhkReferencedObject@@
// Represented subobject at16: .?AVhkpIslandActivationListener@@
// Represented subobject at24: .?AVhkpWorldDeletionListener@@
class hkpSuspendInactiveAgentsUtilRemainingStoragePrefixLayout : public HavokReferencePrefixLayout, public AdditionalInterfacePrefixLayout<2010>, public AdditionalInterfacePrefixLayout<2011> {
public:
    hkpSuspendInactiveAgentsUtilRemainingStoragePrefixLayout();
    ~hkpSuspendInactiveAgentsUtilRemainingStoragePrefixLayout() override;
};
static_assert(sizeof(hkpSuspendInactiveAgentsUtilRemainingStoragePrefixLayout) == 32, "represented initial prefix only");
struct hkpSuspendInactiveAgentsUtilRemainingStoragePrefixLayoutStorageLayout {
    HavokReferencePrefixLayout component0;
    AdditionalInterfacePrefixLayout<2010> component1;
    AdditionalInterfacePrefixLayout<2011> component2;
};
static_assert(sizeof(hkpSuspendInactiveAgentsUtilRemainingStoragePrefixLayoutStorageLayout) == 32, "physical prefix mirror");
static_assert(offsetof(hkpSuspendInactiveAgentsUtilRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(hkpSuspendInactiveAgentsUtilRemainingStoragePrefixLayoutStorageLayout, component1) == 16, "independent target subobject offset");
static_assert(offsetof(hkpSuspendInactiveAgentsUtilRemainingStoragePrefixLayoutStorageLayout, component2) == 24, "independent target subobject offset");
// hkpTriggerVolume: EXE_RTTI
// Owner descriptor: .?AVhkpTriggerVolume@@
// Represented subobject at0: .?AVhkReferencedObject@@
// Represented subobject at16: .?AVhkpContactListener@@
// Represented subobject at24: .?AVhkpWorldPostSimulationListener@@
// Represented subobject at32: .?AVhkpEntityListener@@
class hkpTriggerVolumeRemainingStoragePrefixLayout : public HavokReferencePrefixLayout, public ContactListenerPrefixLayout, public AdditionalInterfacePrefixLayout<2012>, public AdditionalInterfacePrefixLayout<2013> {
public:
    hkpTriggerVolumeRemainingStoragePrefixLayout();
    ~hkpTriggerVolumeRemainingStoragePrefixLayout() override;
};
static_assert(sizeof(hkpTriggerVolumeRemainingStoragePrefixLayout) == 40, "represented initial prefix only");
struct hkpTriggerVolumeRemainingStoragePrefixLayoutStorageLayout {
    HavokReferencePrefixLayout component0;
    ContactListenerPrefixLayout component1;
    AdditionalInterfacePrefixLayout<2012> component2;
    AdditionalInterfacePrefixLayout<2013> component3;
};
static_assert(sizeof(hkpTriggerVolumeRemainingStoragePrefixLayoutStorageLayout) == 40, "physical prefix mirror");
static_assert(offsetof(hkpTriggerVolumeRemainingStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(hkpTriggerVolumeRemainingStoragePrefixLayoutStorageLayout, component1) == 16, "independent target subobject offset");
static_assert(offsetof(hkpTriggerVolumeRemainingStoragePrefixLayoutStorageLayout, component2) == 24, "independent target subobject offset");
static_assert(offsetof(hkpTriggerVolumeRemainingStoragePrefixLayoutStorageLayout, component3) == 32, "independent target subobject offset");
}
