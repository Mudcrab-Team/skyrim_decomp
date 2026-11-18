// Source exposure: mixed (pinned community storage declarations and independent target RTTI/secondary-slot analysis).
// Code origin: adapted community storage declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/TESProduceForm.h,S/SimpleAnimationGraphManagerHolder.h,M/MenuEventHandler.h,I/IMapCameraCallbacks.h,H/hkReferencedObject.h,H/hkpBroadPhaseCastCollector.h,H/hkpEntityListener.h,H/hkpPhantomListener.h,H/hkpWorldPostSimulationListener.h}; MIT.
// TESProduceForm, SimpleAnimationGraphManagerHolder, MenuEventHandler, IMapCameraCallbacks, hkReferencedObject, hkpBroadPhaseCastCollector, hkpEntityListener, hkpPhantomListener, hkpWorldPostSimulationListener: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, Identity tags and physical mirror member names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "../forms/RaceComponentLayout.h"
#include "../forms/TESObjectREFRComponentPrefixLayout.h"
#include "EventInterfaceVptrPrefixLayout.h"
namespace ResearchLayouts {
class HarvestSoundPointeeLayout;
class ProduceItemPointeeLayout;
class AnimationGraphManagerPointeeLayout;
class GraphLoadingTaskPointeeLayout;
struct SeasonalChanceStorageLayout {
    std::int8_t spring, summer, fall, winter;
};
class ProduceComponentPrefixLayout : public FormComponentLayout {
public:
    ~ProduceComponentPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    HarvestSoundPointeeLayout* harvestSound;
    ProduceItemPointeeLayout* produceItem;
    SeasonalChanceStorageLayout produceChance;
};
class SimpleGraphHolderPrefixLayout : public AnimationGraphManagerHolderPrefixLayout {
public:
    ~SimpleGraphHolderPrefixLayout() override;
    AnimationGraphManagerPointeeLayout* animationGraphManager;
    GraphLoadingTaskPointeeLayout* loadingTask;
};
class MenuEventHandlerPrefixLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~MenuEventHandlerPrefixLayout();
    bool registered;
    std::uint8_t unk0D;
};
class MapCameraCallbacksPrefixLayout {
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual ~MapCameraCallbacksPrefixLayout();
};
class HavokReferencePrefixLayout {
public:
    virtual ~HavokReferencePrefixLayout();
    std::uint16_t memSizeAndFlags;
    volatile std::int16_t referenceCount;
};
template<unsigned Identity> class AdditionalInterfacePrefixLayout {
public:
    virtual ~AdditionalInterfacePrefixLayout();
};
static_assert(sizeof(SeasonalChanceStorageLayout) == 4, "public four seasonal chance entries");
static_assert(offsetof(SeasonalChanceStorageLayout, winter) == 3, "fourth public array entry");
static_assert(sizeof(ProduceComponentPrefixLayout) == 32, "public produce component storage");
static_assert(offsetof(ProduceComponentPrefixLayout, harvestSound) == 8, "public harvest pointer offset");
static_assert(offsetof(ProduceComponentPrefixLayout, produceItem) == 16, "public produce pointer offset");
static_assert(offsetof(ProduceComponentPrefixLayout, produceChance) == 24, "public seasonal field group offset");
static_assert(sizeof(SimpleGraphHolderPrefixLayout) == 24, "public graph holder storage");
static_assert(offsetof(SimpleGraphHolderPrefixLayout, animationGraphManager) == 8, "public graph pointer offset");
static_assert(offsetof(SimpleGraphHolderPrefixLayout, loadingTask) == 16, "public loading task pointer offset");
static_assert(sizeof(MenuEventHandlerPrefixLayout) == 16, "public menu event handler storage");
static_assert(offsetof(MenuEventHandlerPrefixLayout, _refCount) == 8, "public inherited count offset");
static_assert(offsetof(MenuEventHandlerPrefixLayout, registered) == 12, "public registered flag offset");
static_assert(offsetof(MenuEventHandlerPrefixLayout, unk0D) == 13, "public unknown byte offset");
static_assert(sizeof(MapCameraCallbacksPrefixLayout) == 8, "public fieldless camera callback interface");
static_assert(sizeof(HavokReferencePrefixLayout) == 16, "public Havok reference storage");
static_assert(offsetof(HavokReferencePrefixLayout, memSizeAndFlags) == 8, "public allocation flags offset");
static_assert(offsetof(HavokReferencePrefixLayout, referenceCount) == 10, "public Havok reference count offset");
static_assert(sizeof(AdditionalInterfacePrefixLayout<0>) == 8, "represented fieldless vptr contract");
// AlchemyItem: EXE_RTTI
// Owner descriptor: .?AVAlchemyItem@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVBGSKeywordForm@@
class AlchemyItemAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public KeywordComponentLayout {
public:
    AlchemyItemAdditionalStoragePrefixLayout();
    ~AlchemyItemAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(AlchemyItemAdditionalStoragePrefixLayout) == 88, "represented initial subobject prefix only");
struct AlchemyItemAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    KeywordComponentLayout component2;
};
static_assert(sizeof(AlchemyItemAdditionalStoragePrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(AlchemyItemAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(AlchemyItemAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(AlchemyItemAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
// AppResourceCaching::(anonymous)::Manager: EXE_RTTI
// Owner descriptor: .?AVManager@?A0xae50f340@AppResourceCaching@@
// Represented subobject at0: .?AV?$BSTEventSink@UNameFoundEvent@BSResource@@@@
// Represented subobject at8: .?AV?$BSTEventSink@UArchiveRegisteredEvent@BSResource@@@@
// Represented subobject at16: .?AV?$BSTEventSink@UTESDataHandlerPostBuildFileListEvent@@@@
class AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayout : public AdditionalInterfacePrefixLayout<1000>, public AdditionalInterfacePrefixLayout<1001>, public AdditionalInterfacePrefixLayout<1002> {
public:
    AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayout();
    ~AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayout) == 24, "represented initial subobject prefix only");
struct AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayoutStorageLayout {
    AdditionalInterfacePrefixLayout<1000> component0;
    AdditionalInterfacePrefixLayout<1001> component1;
    AdditionalInterfacePrefixLayout<1002> component2;
};
static_assert(sizeof(AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayoutStorageLayout) == 24, "physical prefix mirror");
static_assert(offsetof(AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayoutStorageLayout, component1) == 8, "independent target subobject offset");
static_assert(offsetof(AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayoutStorageLayout, component2) == 16, "independent target subobject offset");
// BGSCameraShot: EXE_RTTI
// Owner descriptor: .?AVBGSCameraShot@@
// Represented subobject at0: primary form storage
// Represented subobject at32: .?AVTESModel@@
// Represented subobject at72: .?AVTESImageSpaceModifiableForm@@
class BGSCameraShotAdditionalStoragePrefixLayout : public FormHeaderLayout, public ModelComponentLayout, public ImageSpaceComponentLayout {
public:
    BGSCameraShotAdditionalStoragePrefixLayout();
    ~BGSCameraShotAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSCameraShotAdditionalStoragePrefixLayout) == 88, "represented initial subobject prefix only");
struct BGSCameraShotAdditionalStoragePrefixLayoutStorageLayout {
    FormHeaderLayout component0;
    ModelComponentLayout component1;
    ImageSpaceComponentLayout component2;
};
static_assert(sizeof(BGSCameraShotAdditionalStoragePrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(BGSCameraShotAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(BGSCameraShotAdditionalStoragePrefixLayoutStorageLayout, component1) == 32, "independent target subobject offset");
static_assert(offsetof(BGSCameraShotAdditionalStoragePrefixLayoutStorageLayout, component2) == 72, "independent target subobject offset");
// BGSHeadPart: EXE_RTTI
// Owner descriptor: .?AVBGSHeadPart@@
// Represented subobject at0: primary form storage
// Represented subobject at32: .?AVTESFullName@@
// Represented subobject at48: .?AVTESModelTextureSwap@@
class BGSHeadPartAdditionalStoragePrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout {
public:
    BGSHeadPartAdditionalStoragePrefixLayout();
    ~BGSHeadPartAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSHeadPartAdditionalStoragePrefixLayout) == 104, "represented initial subobject prefix only");
struct BGSHeadPartAdditionalStoragePrefixLayoutStorageLayout {
    FormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
};
static_assert(sizeof(BGSHeadPartAdditionalStoragePrefixLayoutStorageLayout) == 104, "physical prefix mirror");
static_assert(offsetof(BGSHeadPartAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(BGSHeadPartAdditionalStoragePrefixLayoutStorageLayout, component1) == 32, "independent target subobject offset");
static_assert(offsetof(BGSHeadPartAdditionalStoragePrefixLayoutStorageLayout, component2) == 48, "independent target subobject offset");
// BGSImpactManager: EXE_RTTI
// Owner descriptor: .?AVBGSImpactManager@@
// Represented subobject at0: .?AV?$BSTEventSink@UBGSFootstepEvent@@@@
// Represented subobject at8: .?AV?$BSTEventSink@UBGSCombatImpactEvent@@@@
// Represented subobject at16: .?AV?$BSTEventSink@UBGSCollisionSoundEvent@@@@
class BGSImpactManagerAdditionalStoragePrefixLayout : public AdditionalInterfacePrefixLayout<1003>, public AdditionalInterfacePrefixLayout<1004>, public AdditionalInterfacePrefixLayout<1005> {
public:
    BGSImpactManagerAdditionalStoragePrefixLayout();
    ~BGSImpactManagerAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(BGSImpactManagerAdditionalStoragePrefixLayout) == 24, "represented initial subobject prefix only");
struct BGSImpactManagerAdditionalStoragePrefixLayoutStorageLayout {
    AdditionalInterfacePrefixLayout<1003> component0;
    AdditionalInterfacePrefixLayout<1004> component1;
    AdditionalInterfacePrefixLayout<1005> component2;
};
static_assert(sizeof(BGSImpactManagerAdditionalStoragePrefixLayoutStorageLayout) == 24, "physical prefix mirror");
static_assert(offsetof(BGSImpactManagerAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(BGSImpactManagerAdditionalStoragePrefixLayoutStorageLayout, component1) == 8, "independent target subobject offset");
static_assert(offsetof(BGSImpactManagerAdditionalStoragePrefixLayoutStorageLayout, component2) == 16, "independent target subobject offset");
// BGSLocation: EXE_RTTI
// Owner descriptor: .?AVBGSLocation@@
// Represented subobject at0: primary form storage
// Represented subobject at32: .?AVTESFullName@@
// Represented subobject at48: .?AVBGSKeywordForm@@
class BGSLocationAdditionalStoragePrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public KeywordComponentLayout {
public:
    BGSLocationAdditionalStoragePrefixLayout();
    ~BGSLocationAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSLocationAdditionalStoragePrefixLayout) == 72, "represented initial subobject prefix only");
struct BGSLocationAdditionalStoragePrefixLayoutStorageLayout {
    FormHeaderLayout component0;
    FullNameComponentLayout component1;
    KeywordComponentLayout component2;
};
static_assert(sizeof(BGSLocationAdditionalStoragePrefixLayoutStorageLayout) == 72, "physical prefix mirror");
static_assert(offsetof(BGSLocationAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(BGSLocationAdditionalStoragePrefixLayoutStorageLayout, component1) == 32, "independent target subobject offset");
static_assert(offsetof(BGSLocationAdditionalStoragePrefixLayoutStorageLayout, component2) == 48, "independent target subobject offset");
// BGSMessage: EXE_RTTI
// Owner descriptor: .?AVBGSMessage@@
// Represented subobject at0: primary form storage
// Represented subobject at32: .?AVTESFullName@@
// Represented subobject at48: .?AVTESDescription@@
class BGSMessageAdditionalStoragePrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public DescriptionComponentLayout {
public:
    BGSMessageAdditionalStoragePrefixLayout();
    ~BGSMessageAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSMessageAdditionalStoragePrefixLayout) == 64, "represented initial subobject prefix only");
struct BGSMessageAdditionalStoragePrefixLayoutStorageLayout {
    FormHeaderLayout component0;
    FullNameComponentLayout component1;
    DescriptionComponentLayout component2;
};
static_assert(sizeof(BGSMessageAdditionalStoragePrefixLayoutStorageLayout) == 64, "physical prefix mirror");
static_assert(offsetof(BGSMessageAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(BGSMessageAdditionalStoragePrefixLayoutStorageLayout, component1) == 32, "independent target subobject offset");
static_assert(offsetof(BGSMessageAdditionalStoragePrefixLayoutStorageLayout, component2) == 48, "independent target subobject offset");
// BGSSaveLoadManager: EXE_RTTI
// Owner descriptor: .?AVBGSSaveLoadManager@@
// Represented subobject at0: .?AV?$BSTEventSink@VBSSaveDataEvent@@@@
// Represented subobject at8: .?AV?$BSTEventSink@UNameChangedEvent@RaceSexMenuEvent@@@@
// Represented subobject at16: .?AV?$BSTEventSink@VBSSystemEvent@@@@
class BGSSaveLoadManagerAdditionalStoragePrefixLayout : public AdditionalInterfacePrefixLayout<1006>, public AdditionalInterfacePrefixLayout<1007>, public AdditionalInterfacePrefixLayout<1008> {
public:
    BGSSaveLoadManagerAdditionalStoragePrefixLayout();
    ~BGSSaveLoadManagerAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(BGSSaveLoadManagerAdditionalStoragePrefixLayout) == 24, "represented initial subobject prefix only");
struct BGSSaveLoadManagerAdditionalStoragePrefixLayoutStorageLayout {
    AdditionalInterfacePrefixLayout<1006> component0;
    AdditionalInterfacePrefixLayout<1007> component1;
    AdditionalInterfacePrefixLayout<1008> component2;
};
static_assert(sizeof(BGSSaveLoadManagerAdditionalStoragePrefixLayoutStorageLayout) == 24, "physical prefix mirror");
static_assert(offsetof(BGSSaveLoadManagerAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(BGSSaveLoadManagerAdditionalStoragePrefixLayoutStorageLayout, component1) == 8, "independent target subobject offset");
static_assert(offsetof(BGSSaveLoadManagerAdditionalStoragePrefixLayoutStorageLayout, component2) == 16, "independent target subobject offset");
// BookMenu: EXE_RTTI
// Owner descriptor: .?AVBookMenu@@
// Represented subobject at0: .?AVIMenu@@
// Represented subobject at48: .?AVSimpleAnimationGraphManagerHolder@@
// Represented subobject at72: .?AV?$BSTEventSink@UBSAnimationGraphEvent@@@@
class BookMenuAdditionalStoragePrefixLayout : public MenuStoragePrefixLayout, public SimpleGraphHolderPrefixLayout, public AdditionalInterfacePrefixLayout<1009> {
public:
    BookMenuAdditionalStoragePrefixLayout();
    ~BookMenuAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(BookMenuAdditionalStoragePrefixLayout) == 80, "represented initial subobject prefix only");
struct BookMenuAdditionalStoragePrefixLayoutStorageLayout {
    MenuStoragePrefixLayout component0;
    SimpleGraphHolderPrefixLayout component1;
    AdditionalInterfacePrefixLayout<1009> component2;
};
static_assert(sizeof(BookMenuAdditionalStoragePrefixLayoutStorageLayout) == 80, "physical prefix mirror");
static_assert(offsetof(BookMenuAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(BookMenuAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(BookMenuAdditionalStoragePrefixLayoutStorageLayout, component2) == 72, "independent target subobject offset");
// EnchantmentItem: EXE_RTTI
// Owner descriptor: .?AVEnchantmentItem@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVBGSKeywordForm@@
class EnchantmentItemAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public KeywordComponentLayout {
public:
    EnchantmentItemAdditionalStoragePrefixLayout();
    ~EnchantmentItemAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(EnchantmentItemAdditionalStoragePrefixLayout) == 88, "represented initial subobject prefix only");
struct EnchantmentItemAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    KeywordComponentLayout component2;
};
static_assert(sizeof(EnchantmentItemAdditionalStoragePrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(EnchantmentItemAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(EnchantmentItemAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(EnchantmentItemAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
// HUDMenu: EXE_RTTI
// Owner descriptor: .?AVHUDMenu@@
// Represented subobject at0: .?AVIMenu@@
// Represented subobject at48: .?AV?$BSTEventSink@VUserEventEnabledEvent@@@@
// Represented subobject at56: .?AV?$BSTEventSink@UBSRemoteGamepadEvent@@@@
class HUDMenuAdditionalStoragePrefixLayout : public MenuStoragePrefixLayout, public AdditionalInterfacePrefixLayout<1010>, public AdditionalInterfacePrefixLayout<1011> {
public:
    HUDMenuAdditionalStoragePrefixLayout();
    ~HUDMenuAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(HUDMenuAdditionalStoragePrefixLayout) == 64, "represented initial subobject prefix only");
struct HUDMenuAdditionalStoragePrefixLayoutStorageLayout {
    MenuStoragePrefixLayout component0;
    AdditionalInterfacePrefixLayout<1010> component1;
    AdditionalInterfacePrefixLayout<1011> component2;
};
static_assert(sizeof(HUDMenuAdditionalStoragePrefixLayoutStorageLayout) == 64, "physical prefix mirror");
static_assert(offsetof(HUDMenuAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(HUDMenuAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(HUDMenuAdditionalStoragePrefixLayoutStorageLayout, component2) == 56, "independent target subobject offset");
// IngredientItem: EXE_RTTI
// Owner descriptor: .?AVIngredientItem@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVBGSKeywordForm@@
class IngredientItemAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public KeywordComponentLayout {
public:
    IngredientItemAdditionalStoragePrefixLayout();
    ~IngredientItemAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(IngredientItemAdditionalStoragePrefixLayout) == 88, "represented initial subobject prefix only");
struct IngredientItemAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    KeywordComponentLayout component2;
};
static_assert(sizeof(IngredientItemAdditionalStoragePrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(IngredientItemAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(IngredientItemAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(IngredientItemAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
// JournalMenu: EXE_RTTI
// Owner descriptor: .?AVJournalMenu@@
// Represented subobject at0: .?AVIMenu@@
// Represented subobject at48: .?AVMenuEventHandler@@
// Represented subobject at64: .?AV?$BSTEventSink@VBSSystemEvent@@@@
class JournalMenuAdditionalStoragePrefixLayout : public MenuStoragePrefixLayout, public MenuEventHandlerPrefixLayout, public AdditionalInterfacePrefixLayout<1012> {
public:
    JournalMenuAdditionalStoragePrefixLayout();
    ~JournalMenuAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(JournalMenuAdditionalStoragePrefixLayout) == 72, "represented initial subobject prefix only");
struct JournalMenuAdditionalStoragePrefixLayoutStorageLayout {
    MenuStoragePrefixLayout component0;
    MenuEventHandlerPrefixLayout component1;
    AdditionalInterfacePrefixLayout<1012> component2;
};
static_assert(sizeof(JournalMenuAdditionalStoragePrefixLayoutStorageLayout) == 72, "physical prefix mirror");
static_assert(offsetof(JournalMenuAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(JournalMenuAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(JournalMenuAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
// LockpickingMenu: EXE_RTTI
// Owner descriptor: .?AVLockpickingMenu@@
// Represented subobject at0: .?AVIMenu@@
// Represented subobject at48: .?AVMenuEventHandler@@
// Represented subobject at64: .?AV?$BSTEventSink@VMenuOpenCloseEvent@@@@
class LockpickingMenuAdditionalStoragePrefixLayout : public MenuStoragePrefixLayout, public MenuEventHandlerPrefixLayout, public AdditionalInterfacePrefixLayout<1013> {
public:
    LockpickingMenuAdditionalStoragePrefixLayout();
    ~LockpickingMenuAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(LockpickingMenuAdditionalStoragePrefixLayout) == 72, "represented initial subobject prefix only");
struct LockpickingMenuAdditionalStoragePrefixLayoutStorageLayout {
    MenuStoragePrefixLayout component0;
    MenuEventHandlerPrefixLayout component1;
    AdditionalInterfacePrefixLayout<1013> component2;
};
static_assert(sizeof(LockpickingMenuAdditionalStoragePrefixLayoutStorageLayout) == 72, "physical prefix mirror");
static_assert(offsetof(LockpickingMenuAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(LockpickingMenuAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(LockpickingMenuAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
// MagicItem: EXE_RTTI
// Owner descriptor: .?AVMagicItem@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVBGSKeywordForm@@
class MagicItemAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public KeywordComponentLayout {
public:
    MagicItemAdditionalStoragePrefixLayout();
    ~MagicItemAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(MagicItemAdditionalStoragePrefixLayout) == 88, "represented initial subobject prefix only");
struct MagicItemAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    KeywordComponentLayout component2;
};
static_assert(sizeof(MagicItemAdditionalStoragePrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(MagicItemAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(MagicItemAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(MagicItemAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
// MapMenu: EXE_RTTI
// Owner descriptor: .?AVMapMenu@@
// Represented subobject at0: .?AVIMenu@@
// Represented subobject at48: .?AV?$BSTEventSink@VMenuOpenCloseEvent@@@@
// Represented subobject at56: .?AUIMapCameraCallbacks@@
class MapMenuAdditionalStoragePrefixLayout : public MenuStoragePrefixLayout, public AdditionalInterfacePrefixLayout<1014>, public MapCameraCallbacksPrefixLayout {
public:
    MapMenuAdditionalStoragePrefixLayout();
    ~MapMenuAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(MapMenuAdditionalStoragePrefixLayout) == 64, "represented initial subobject prefix only");
struct MapMenuAdditionalStoragePrefixLayoutStorageLayout {
    MenuStoragePrefixLayout component0;
    AdditionalInterfacePrefixLayout<1014> component1;
    MapCameraCallbacksPrefixLayout component2;
};
static_assert(sizeof(MapMenuAdditionalStoragePrefixLayoutStorageLayout) == 64, "physical prefix mirror");
static_assert(offsetof(MapMenuAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(MapMenuAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(MapMenuAdditionalStoragePrefixLayoutStorageLayout, component2) == 56, "independent target subobject offset");
// MistMenu: EXE_RTTI
// Owner descriptor: .?AVMistMenu@@
// Represented subobject at0: .?AVIMenu@@
// Represented subobject at48: .?AVSimpleAnimationGraphManagerHolder@@
// Represented subobject at72: .?AVMenuEventHandler@@
class MistMenuAdditionalStoragePrefixLayout : public MenuStoragePrefixLayout, public SimpleGraphHolderPrefixLayout, public MenuEventHandlerPrefixLayout {
public:
    MistMenuAdditionalStoragePrefixLayout();
    ~MistMenuAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(MistMenuAdditionalStoragePrefixLayout) == 88, "represented initial subobject prefix only");
struct MistMenuAdditionalStoragePrefixLayoutStorageLayout {
    MenuStoragePrefixLayout component0;
    SimpleGraphHolderPrefixLayout component1;
    MenuEventHandlerPrefixLayout component2;
};
static_assert(sizeof(MistMenuAdditionalStoragePrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(MistMenuAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(MistMenuAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(MistMenuAdditionalStoragePrefixLayoutStorageLayout, component2) == 72, "independent target subobject offset");
// ModManagerMenu: EXE_RTTI
// Owner descriptor: .?AVModManagerMenu@@
// Represented subobject at0: .?AVIMenu@@
// Represented subobject at48: .?AVMenuEventHandler@@
// Represented subobject at64: .?AVGFxFunctionHandler@@
class ModManagerMenuAdditionalStoragePrefixLayout : public MenuStoragePrefixLayout, public MenuEventHandlerPrefixLayout, public GRefCountImplStorageLayout {
public:
    ModManagerMenuAdditionalStoragePrefixLayout();
    ~ModManagerMenuAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(ModManagerMenuAdditionalStoragePrefixLayout) == 80, "represented initial subobject prefix only");
struct ModManagerMenuAdditionalStoragePrefixLayoutStorageLayout {
    MenuStoragePrefixLayout component0;
    MenuEventHandlerPrefixLayout component1;
    GRefCountImplStorageLayout component2;
};
static_assert(sizeof(ModManagerMenuAdditionalStoragePrefixLayoutStorageLayout) == 80, "physical prefix mirror");
static_assert(offsetof(ModManagerMenuAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(ModManagerMenuAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(ModManagerMenuAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
// SkyrimScript::QuestCallbackMgr: EXE_RTTI
// Owner descriptor: .?AVQuestCallbackMgr@SkyrimScript@@
// Represented subobject at0: .?AV?$BSTEventSink@UTESQuestStageItemDoneEvent@@@@
// Represented subobject at8: .?AV?$BSTEventSink@UTESQuestStartStopEvent@@@@
// Represented subobject at16: .?AV?$BSTEventSink@UBGSEventProcessedEvent@@@@
class SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayout : public AdditionalInterfacePrefixLayout<1015>, public AdditionalInterfacePrefixLayout<1016>, public AdditionalInterfacePrefixLayout<1017> {
public:
    SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayout();
    ~SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayout) == 24, "represented initial subobject prefix only");
struct SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayoutStorageLayout {
    AdditionalInterfacePrefixLayout<1015> component0;
    AdditionalInterfacePrefixLayout<1016> component1;
    AdditionalInterfacePrefixLayout<1017> component2;
};
static_assert(sizeof(SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayoutStorageLayout) == 24, "physical prefix mirror");
static_assert(offsetof(SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayoutStorageLayout, component1) == 8, "independent target subobject offset");
static_assert(offsetof(SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayoutStorageLayout, component2) == 16, "independent target subobject offset");
// SpellItem: EXE_RTTI
// Owner descriptor: .?AVSpellItem@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVBGSKeywordForm@@
class SpellItemAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public KeywordComponentLayout {
public:
    SpellItemAdditionalStoragePrefixLayout();
    ~SpellItemAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(SpellItemAdditionalStoragePrefixLayout) == 88, "represented initial subobject prefix only");
struct SpellItemAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    KeywordComponentLayout component2;
};
static_assert(sizeof(SpellItemAdditionalStoragePrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(SpellItemAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(SpellItemAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(SpellItemAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
// TESEyes: EXE_RTTI
// Owner descriptor: .?AVTESEyes@@
// Represented subobject at0: primary form storage
// Represented subobject at32: .?AVTESFullName@@
// Represented subobject at48: .?AVTESTexture@@
class TESEyesAdditionalStoragePrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public TextureComponentLayout {
public:
    TESEyesAdditionalStoragePrefixLayout();
    ~TESEyesAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESEyesAdditionalStoragePrefixLayout) == 64, "represented initial subobject prefix only");
struct TESEyesAdditionalStoragePrefixLayoutStorageLayout {
    FormHeaderLayout component0;
    FullNameComponentLayout component1;
    TextureComponentLayout component2;
};
static_assert(sizeof(TESEyesAdditionalStoragePrefixLayoutStorageLayout) == 64, "physical prefix mirror");
static_assert(offsetof(TESEyesAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESEyesAdditionalStoragePrefixLayoutStorageLayout, component1) == 32, "independent target subobject offset");
static_assert(offsetof(TESEyesAdditionalStoragePrefixLayoutStorageLayout, component2) == 48, "independent target subobject offset");
// TESObjectLIGH: EXE_RTTI
// Owner descriptor: .?AVTESObjectLIGH@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVTESModelTextureSwap@@
// Represented subobject at120: .?AVTESIcon@@
class TESObjectLIGHAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout {
public:
    TESObjectLIGHAdditionalStoragePrefixLayout();
    ~TESObjectLIGHAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectLIGHAdditionalStoragePrefixLayout) == 136, "represented initial subobject prefix only");
struct TESObjectLIGHAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
    IconComponentLayout component3;
};
static_assert(sizeof(TESObjectLIGHAdditionalStoragePrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESObjectLIGHAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESObjectLIGHAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(TESObjectLIGHAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
static_assert(offsetof(TESObjectLIGHAdditionalStoragePrefixLayoutStorageLayout, component3) == 120, "independent target subobject offset");
// TESObjectMISC: EXE_RTTI
// Owner descriptor: .?AVTESObjectMISC@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVTESModelTextureSwap@@
// Represented subobject at120: .?AVTESIcon@@
class TESObjectMISCAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout {
public:
    TESObjectMISCAdditionalStoragePrefixLayout();
    ~TESObjectMISCAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectMISCAdditionalStoragePrefixLayout) == 136, "represented initial subobject prefix only");
struct TESObjectMISCAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
    IconComponentLayout component3;
};
static_assert(sizeof(TESObjectMISCAdditionalStoragePrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESObjectMISCAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESObjectMISCAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(TESObjectMISCAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
static_assert(offsetof(TESObjectMISCAdditionalStoragePrefixLayoutStorageLayout, component3) == 120, "independent target subobject offset");
// TESObjectREFR: EXE_RTTI
// Owner descriptor: .?AVTESObjectREFR@@
// Represented subobject at0: .?AVTESObjectREFR@@
class TESObjectREFRAdditionalStoragePrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    TESObjectREFRAdditionalStoragePrefixLayout();
    ~TESObjectREFRAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectREFRAdditionalStoragePrefixLayout) == 64, "represented initial subobject prefix only");
struct TESObjectREFRAdditionalStoragePrefixLayoutStorageLayout {
    TESObjectREFRComponentPrefixLayout component0;
};
static_assert(sizeof(TESObjectREFRAdditionalStoragePrefixLayoutStorageLayout) == 64, "physical prefix mirror");
static_assert(offsetof(TESObjectREFRAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
// TESObjectTREE: EXE_RTTI
// Owner descriptor: .?AVTESObjectTREE@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESModel@@
// Represented subobject at88: .?AVTESFullName@@
// Represented subobject at104: .?AVTESProduceForm@@
class TESObjectTREEAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public ModelComponentLayout, public FullNameComponentLayout, public ProduceComponentPrefixLayout {
public:
    TESObjectTREEAdditionalStoragePrefixLayout();
    ~TESObjectTREEAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectTREEAdditionalStoragePrefixLayout) == 136, "represented initial subobject prefix only");
struct TESObjectTREEAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    ModelComponentLayout component1;
    FullNameComponentLayout component2;
    ProduceComponentPrefixLayout component3;
};
static_assert(sizeof(TESObjectTREEAdditionalStoragePrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESObjectTREEAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESObjectTREEAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(TESObjectTREEAdditionalStoragePrefixLayoutStorageLayout, component2) == 88, "independent target subobject offset");
static_assert(offsetof(TESObjectTREEAdditionalStoragePrefixLayoutStorageLayout, component3) == 104, "independent target subobject offset");
// TESObjectWEAP: EXE_RTTI
// Owner descriptor: .?AVTESObjectWEAP@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVTESModelTextureSwap@@
// Represented subobject at120: .?AVTESIcon@@
class TESObjectWEAPAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout {
public:
    TESObjectWEAPAdditionalStoragePrefixLayout();
    ~TESObjectWEAPAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectWEAPAdditionalStoragePrefixLayout) == 136, "represented initial subobject prefix only");
struct TESObjectWEAPAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
    IconComponentLayout component3;
};
static_assert(sizeof(TESObjectWEAPAdditionalStoragePrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESObjectWEAPAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESObjectWEAPAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(TESObjectWEAPAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
static_assert(offsetof(TESObjectWEAPAdditionalStoragePrefixLayoutStorageLayout, component3) == 120, "independent target subobject offset");
// TESSoulGem: EXE_RTTI
// Owner descriptor: .?AVTESSoulGem@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVTESModelTextureSwap@@
// Represented subobject at120: .?AVTESIcon@@
class TESSoulGemAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout {
public:
    TESSoulGemAdditionalStoragePrefixLayout();
    ~TESSoulGemAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESSoulGemAdditionalStoragePrefixLayout) == 136, "represented initial subobject prefix only");
struct TESSoulGemAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
    IconComponentLayout component3;
};
static_assert(sizeof(TESSoulGemAdditionalStoragePrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESSoulGemAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(TESSoulGemAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(TESSoulGemAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
static_assert(offsetof(TESSoulGemAdditionalStoragePrefixLayoutStorageLayout, component3) == 120, "independent target subobject offset");
// ahkpCharacterRigidBody: EXE_RTTI
// Owner descriptor: .?AVahkpCharacterRigidBody@@
// Represented subobject at0: .?AVhkReferencedObject@@
// Represented subobject at16: .?AVhkpEntityListener@@
// Represented subobject at24: .?AVhkpWorldPostSimulationListener@@
class ahkpCharacterRigidBodyAdditionalStoragePrefixLayout : public HavokReferencePrefixLayout, public AdditionalInterfacePrefixLayout<1018>, public AdditionalInterfacePrefixLayout<1019> {
public:
    ahkpCharacterRigidBodyAdditionalStoragePrefixLayout();
    ~ahkpCharacterRigidBodyAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(ahkpCharacterRigidBodyAdditionalStoragePrefixLayout) == 32, "represented initial subobject prefix only");
struct ahkpCharacterRigidBodyAdditionalStoragePrefixLayoutStorageLayout {
    HavokReferencePrefixLayout component0;
    AdditionalInterfacePrefixLayout<1018> component1;
    AdditionalInterfacePrefixLayout<1019> component2;
};
static_assert(sizeof(ahkpCharacterRigidBodyAdditionalStoragePrefixLayoutStorageLayout) == 32, "physical prefix mirror");
static_assert(offsetof(ahkpCharacterRigidBodyAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(ahkpCharacterRigidBodyAdditionalStoragePrefixLayoutStorageLayout, component1) == 16, "independent target subobject offset");
static_assert(offsetof(ahkpCharacterRigidBodyAdditionalStoragePrefixLayoutStorageLayout, component2) == 24, "independent target subobject offset");
// hkCpuWorldLinearCastCollector: EXE_RTTI
// Owner descriptor: .?AVhkCpuWorldLinearCastCollector@@
// Represented subobject at0: .?AVhkpBroadPhaseCastCollector@@
// Represented subobject at8: .?AVhkKdTreeCastCollector@@
// Represented subobject at16: .?AUCollector@?$hkAabbTreeQueryUtils@UhkAabbTreeAabb@hkAabbTreeData@@G@@
// Represented subobject at24: .?AUCollector@?$hkAabbTreeQueryUtils@UhkAabbTreeAabb16@hkAabbTreeData@@G@@
class hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayout : public AdditionalInterfacePrefixLayout<1020>, public AdditionalInterfacePrefixLayout<1021>, public AdditionalInterfacePrefixLayout<1022>, public AdditionalInterfacePrefixLayout<1023> {
public:
    hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayout();
    ~hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayout) == 32, "represented initial subobject prefix only");
struct hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayoutStorageLayout {
    AdditionalInterfacePrefixLayout<1020> component0;
    AdditionalInterfacePrefixLayout<1021> component1;
    AdditionalInterfacePrefixLayout<1022> component2;
    AdditionalInterfacePrefixLayout<1023> component3;
};
static_assert(sizeof(hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayoutStorageLayout) == 32, "physical prefix mirror");
static_assert(offsetof(hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayoutStorageLayout, component1) == 8, "independent target subobject offset");
static_assert(offsetof(hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayoutStorageLayout, component2) == 16, "independent target subobject offset");
static_assert(offsetof(hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayoutStorageLayout, component3) == 24, "independent target subobject offset");
// hkCpuWorldRayCastCollector: EXE_RTTI
// Owner descriptor: .?AVhkCpuWorldRayCastCollector@@
// Represented subobject at0: .?AVhkpBroadPhaseCastCollector@@
// Represented subobject at8: .?AVhkKdTreeCastCollector@@
// Represented subobject at16: .?AUCollector@?$hkAabbTreeQueryUtils@UhkAabbTreeAabb@hkAabbTreeData@@G@@
// Represented subobject at24: .?AUCollector@?$hkAabbTreeQueryUtils@UhkAabbTreeAabb16@hkAabbTreeData@@G@@
class hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayout : public AdditionalInterfacePrefixLayout<1024>, public AdditionalInterfacePrefixLayout<1025>, public AdditionalInterfacePrefixLayout<1026>, public AdditionalInterfacePrefixLayout<1027> {
public:
    hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayout();
    ~hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayout) == 32, "represented initial subobject prefix only");
struct hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayoutStorageLayout {
    AdditionalInterfacePrefixLayout<1024> component0;
    AdditionalInterfacePrefixLayout<1025> component1;
    AdditionalInterfacePrefixLayout<1026> component2;
    AdditionalInterfacePrefixLayout<1027> component3;
};
static_assert(sizeof(hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayoutStorageLayout) == 32, "physical prefix mirror");
static_assert(offsetof(hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayoutStorageLayout, component1) == 8, "independent target subobject offset");
static_assert(offsetof(hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayoutStorageLayout, component2) == 16, "independent target subobject offset");
static_assert(offsetof(hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayoutStorageLayout, component3) == 24, "independent target subobject offset");
// ScrollItem: EXE_RTTI
// Owner descriptor: .?AVScrollItem@@
// Represented subobject at0: primary form storage
// Represented subobject at48: .?AVTESFullName@@
// Represented subobject at64: .?AVBGSKeywordForm@@
class ScrollItemAdditionalStoragePrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public KeywordComponentLayout {
public:
    ScrollItemAdditionalStoragePrefixLayout();
    ~ScrollItemAdditionalStoragePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(ScrollItemAdditionalStoragePrefixLayout) == 88, "represented initial subobject prefix only");
struct ScrollItemAdditionalStoragePrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    KeywordComponentLayout component2;
};
static_assert(sizeof(ScrollItemAdditionalStoragePrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(ScrollItemAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(ScrollItemAdditionalStoragePrefixLayoutStorageLayout, component1) == 48, "independent target subobject offset");
static_assert(offsetof(ScrollItemAdditionalStoragePrefixLayoutStorageLayout, component2) == 64, "independent target subobject offset");
// ahkpCharacterProxy: EXE_RTTI
// Owner descriptor: .?AVahkpCharacterProxy@@
// Represented subobject at0: .?AVhkReferencedObject@@
// Represented subobject at16: .?AVhkpEntityListener@@
// Represented subobject at24: .?AVhkpPhantomListener@@
class ahkpCharacterProxyAdditionalStoragePrefixLayout : public HavokReferencePrefixLayout, public AdditionalInterfacePrefixLayout<1028>, public AdditionalInterfacePrefixLayout<1029> {
public:
    ahkpCharacterProxyAdditionalStoragePrefixLayout();
    ~ahkpCharacterProxyAdditionalStoragePrefixLayout() override;
};
static_assert(sizeof(ahkpCharacterProxyAdditionalStoragePrefixLayout) == 32, "represented initial subobject prefix only");
struct ahkpCharacterProxyAdditionalStoragePrefixLayoutStorageLayout {
    HavokReferencePrefixLayout component0;
    AdditionalInterfacePrefixLayout<1028> component1;
    AdditionalInterfacePrefixLayout<1029> component2;
};
static_assert(sizeof(ahkpCharacterProxyAdditionalStoragePrefixLayoutStorageLayout) == 32, "physical prefix mirror");
static_assert(offsetof(ahkpCharacterProxyAdditionalStoragePrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(ahkpCharacterProxyAdditionalStoragePrefixLayoutStorageLayout, component1) == 16, "independent target subobject offset");
static_assert(offsetof(ahkpCharacterProxyAdditionalStoragePrefixLayoutStorageLayout, component2) == 24, "independent target subobject offset");
}
