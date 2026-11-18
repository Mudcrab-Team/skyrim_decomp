// Source exposure: mixed (pinned community component storage and independent target RTTI/secondary-slot analysis).
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/TESRaceForm.h,T/TESEnchantableForm.h,T/TESValueForm.h,T/TESWeightForm.h,T/TESModelTextureSwap.h,T/TESContainer.h,B/BGSMenuDisplayObject.h,B/BGSEquipType.h}; MIT.
// TESRaceForm, TESEnchantableForm, TESValueForm, TESWeightForm, TESModelTextureSwap, TESContainer, BGSMenuDisplayObject, BGSEquipType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, and physical mirror member names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "FormComponentLayout.h"
namespace ResearchLayouts {
class RacePointeeLayout;
class EnchantmentPointeeLayout;
class AlternateTexturePointeeLayout;
class ContainerObjectPointeeLayout;
class MenuBoundObjectPointeeLayout;
class EquipSlotPointeeLayout;
class RaceComponentLayout : public FormComponentLayout {
public:
    ~RaceComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    RacePointeeLayout* race;
};
static_assert(sizeof(RaceComponentLayout) == 16, "pinned public component storage");
static_assert(offsetof(RaceComponentLayout, race) == 8, "pinned public component member offset");
class EnchantableComponentLayout : public FormComponentLayout {
public:
    ~EnchantableComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    EnchantmentPointeeLayout* formEnchanting;
    std::uint16_t castingType;
    std::uint16_t amountofEnchantment;
};
static_assert(sizeof(EnchantableComponentLayout) == 24, "pinned public component storage");
static_assert(offsetof(EnchantableComponentLayout, formEnchanting) == 8, "pinned public component member offset");
static_assert(offsetof(EnchantableComponentLayout, castingType) == 16, "pinned public component member offset");
static_assert(offsetof(EnchantableComponentLayout, amountofEnchantment) == 18, "pinned public component member offset");
class ValueComponentLayout : public FormComponentLayout {
public:
    ~ValueComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    std::int32_t value;
};
static_assert(sizeof(ValueComponentLayout) == 16, "pinned public component storage");
static_assert(offsetof(ValueComponentLayout, value) == 8, "pinned public component member offset");
class WeightComponentLayout : public FormComponentLayout {
public:
    ~WeightComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    float weight;
};
static_assert(sizeof(WeightComponentLayout) == 16, "pinned public component storage");
static_assert(offsetof(WeightComponentLayout, weight) == 8, "pinned public component member offset");
class ModelTextureSwapComponentLayout : public ModelComponentLayout {
public:
    ~ModelTextureSwapComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    AlternateTexturePointeeLayout* alternateTextures;
    std::uint32_t numAlternateTextures;
};
static_assert(sizeof(ModelTextureSwapComponentLayout) == 56, "pinned public component storage");
static_assert(offsetof(ModelTextureSwapComponentLayout, alternateTextures) == 40, "pinned public component member offset");
static_assert(offsetof(ModelTextureSwapComponentLayout, numAlternateTextures) == 48, "pinned public component member offset");
class ContainerComponentLayout : public FormComponentLayout {
public:
    ~ContainerComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    ContainerObjectPointeeLayout** containerObjects;
    std::uint32_t numContainerObjects;
};
static_assert(sizeof(ContainerComponentLayout) == 24, "pinned public component storage");
static_assert(offsetof(ContainerComponentLayout, containerObjects) == 8, "pinned public component member offset");
static_assert(offsetof(ContainerComponentLayout, numContainerObjects) == 16, "pinned public component member offset");
class MenuDisplayComponentLayout : public FormComponentLayout {
public:
    ~MenuDisplayComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    MenuBoundObjectPointeeLayout* menuDispObject;
};
static_assert(sizeof(MenuDisplayComponentLayout) == 16, "pinned public component storage");
static_assert(offsetof(MenuDisplayComponentLayout, menuDispObject) == 8, "pinned public component member offset");
class EquipTypeComponentLayout : public FormComponentLayout {
public:
    ~EquipTypeComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    EquipSlotPointeeLayout* equipSlot;
};
static_assert(sizeof(EquipTypeComponentLayout) == 16, "pinned public component storage");
static_assert(offsetof(EquipTypeComponentLayout, equipSlot) == 8, "pinned public component member offset");
// ActorValueInfo: EXE_RTTI
// Owner descriptor: .?AVActorValueInfo@@
// Represented component at32: .?AVTESFullName@@
// Represented component at48: .?AVTESDescription@@
// Represented component at64: .?AVTESIcon@@
class ActorValueInfoExtendedFormPrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public DescriptionComponentLayout, public IconComponentLayout {
public:
    ActorValueInfoExtendedFormPrefixLayout();
    ~ActorValueInfoExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(ActorValueInfoExtendedFormPrefixLayout) == 80, "represented initial component prefix only");
struct ActorValueInfoExtendedFormPrefixLayoutStorageLayout {
    FormHeaderLayout primary;
    FullNameComponentLayout component0;
    DescriptionComponentLayout component1;
    IconComponentLayout component2;
};
static_assert(sizeof(ActorValueInfoExtendedFormPrefixLayoutStorageLayout) == 80, "physical prefix mirror");
static_assert(offsetof(ActorValueInfoExtendedFormPrefixLayoutStorageLayout, component0) == 32, "independent target component offset");
static_assert(offsetof(ActorValueInfoExtendedFormPrefixLayoutStorageLayout, component1) == 48, "independent target component offset");
static_assert(offsetof(ActorValueInfoExtendedFormPrefixLayoutStorageLayout, component2) == 64, "independent target component offset");
// BGSApparatus: EXE_RTTI
// Owner descriptor: .?AVBGSApparatus@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModelTextureSwap@@
// Represented component at120: .?AVTESIcon@@
class BGSApparatusExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout {
public:
    BGSApparatusExtendedFormPrefixLayout();
    ~BGSApparatusExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSApparatusExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct BGSApparatusExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelTextureSwapComponentLayout component1;
    IconComponentLayout component2;
};
static_assert(sizeof(BGSApparatusExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(BGSApparatusExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(BGSApparatusExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(BGSApparatusExtendedFormPrefixLayoutStorageLayout, component2) == 120, "independent target component offset");
// BGSBodyPartData: EXE_RTTI
// Owner descriptor: .?AVBGSBodyPartData@@
// Represented component at32: .?AVTESModel@@
// Represented component at72: .?AVBGSPreloadable@@
class BGSBodyPartDataExtendedFormPrefixLayout : public FormHeaderLayout, public ModelComponentLayout, public PreloadableComponentLayout {
public:
    BGSBodyPartDataExtendedFormPrefixLayout();
    ~BGSBodyPartDataExtendedFormPrefixLayout() override;
    void Unk_04() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSBodyPartDataExtendedFormPrefixLayout) == 80, "represented initial component prefix only");
struct BGSBodyPartDataExtendedFormPrefixLayoutStorageLayout {
    FormHeaderLayout primary;
    ModelComponentLayout component0;
    PreloadableVptrStorageLayout component1;
};
static_assert(sizeof(BGSBodyPartDataExtendedFormPrefixLayoutStorageLayout) == 80, "physical prefix mirror");
static_assert(offsetof(BGSBodyPartDataExtendedFormPrefixLayoutStorageLayout, component0) == 32, "independent target component offset");
static_assert(offsetof(BGSBodyPartDataExtendedFormPrefixLayoutStorageLayout, component1) == 72, "independent target component offset");
// BGSExplosion: EXE_RTTI
// Owner descriptor: .?AVBGSExplosion@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModel@@
// Represented component at104: .?AVTESEnchantableForm@@
class BGSExplosionExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelComponentLayout, public EnchantableComponentLayout {
public:
    BGSExplosionExtendedFormPrefixLayout();
    ~BGSExplosionExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSExplosionExtendedFormPrefixLayout) == 128, "represented initial component prefix only");
struct BGSExplosionExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelComponentLayout component1;
    EnchantableComponentLayout component2;
};
static_assert(sizeof(BGSExplosionExtendedFormPrefixLayoutStorageLayout) == 128, "physical prefix mirror");
static_assert(offsetof(BGSExplosionExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(BGSExplosionExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(BGSExplosionExtendedFormPrefixLayoutStorageLayout, component2) == 104, "independent target component offset");
// BGSPerk: EXE_RTTI
// Owner descriptor: .?AVBGSPerk@@
// Represented component at32: .?AVTESFullName@@
// Represented component at48: .?AVTESDescription@@
// Represented component at64: .?AVTESIcon@@
class BGSPerkExtendedFormPrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public DescriptionComponentLayout, public IconComponentLayout {
public:
    BGSPerkExtendedFormPrefixLayout();
    ~BGSPerkExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSPerkExtendedFormPrefixLayout) == 80, "represented initial component prefix only");
struct BGSPerkExtendedFormPrefixLayoutStorageLayout {
    FormHeaderLayout primary;
    FullNameComponentLayout component0;
    DescriptionComponentLayout component1;
    IconComponentLayout component2;
};
static_assert(sizeof(BGSPerkExtendedFormPrefixLayoutStorageLayout) == 80, "physical prefix mirror");
static_assert(offsetof(BGSPerkExtendedFormPrefixLayoutStorageLayout, component0) == 32, "independent target component offset");
static_assert(offsetof(BGSPerkExtendedFormPrefixLayoutStorageLayout, component1) == 48, "independent target component offset");
static_assert(offsetof(BGSPerkExtendedFormPrefixLayoutStorageLayout, component2) == 64, "independent target component offset");
// BGSTalkingActivator: EXE_RTTI
// Owner descriptor: .?AVBGSTalkingActivator@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModelTextureSwap@@
// Represented component at120: .?AVBGSDestructibleObjectForm@@
class BGSTalkingActivatorExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public DestructibleComponentLayout {
public:
    BGSTalkingActivatorExtendedFormPrefixLayout();
    ~BGSTalkingActivatorExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSTalkingActivatorExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct BGSTalkingActivatorExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelTextureSwapComponentLayout component1;
    DestructibleComponentLayout component2;
};
static_assert(sizeof(BGSTalkingActivatorExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(BGSTalkingActivatorExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(BGSTalkingActivatorExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(BGSTalkingActivatorExtendedFormPrefixLayoutStorageLayout, component2) == 120, "independent target component offset");
// EffectSetting: EXE_RTTI
// Owner descriptor: .?AVEffectSetting@@
// Represented component at32: .?AVTESFullName@@
// Represented component at48: .?AVBGSMenuDisplayObject@@
// Represented component at64: .?AVBGSKeywordForm@@
class EffectSettingExtendedFormPrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public MenuDisplayComponentLayout, public KeywordComponentLayout {
public:
    EffectSettingExtendedFormPrefixLayout();
    ~EffectSettingExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(EffectSettingExtendedFormPrefixLayout) == 88, "represented initial component prefix only");
struct EffectSettingExtendedFormPrefixLayoutStorageLayout {
    FormHeaderLayout primary;
    FullNameComponentLayout component0;
    MenuDisplayComponentLayout component1;
    KeywordComponentLayout component2;
};
static_assert(sizeof(EffectSettingExtendedFormPrefixLayoutStorageLayout) == 88, "physical prefix mirror");
static_assert(offsetof(EffectSettingExtendedFormPrefixLayoutStorageLayout, component0) == 32, "independent target component offset");
static_assert(offsetof(EffectSettingExtendedFormPrefixLayoutStorageLayout, component1) == 48, "independent target component offset");
static_assert(offsetof(EffectSettingExtendedFormPrefixLayoutStorageLayout, component2) == 64, "independent target component offset");
// TESAmmo: EXE_RTTI
// Owner descriptor: .?AVTESAmmo@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModelTextureSwap@@
// Represented component at120: .?AVTESIcon@@
class TESAmmoExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout {
public:
    TESAmmoExtendedFormPrefixLayout();
    ~TESAmmoExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESAmmoExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct TESAmmoExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelTextureSwapComponentLayout component1;
    IconComponentLayout component2;
};
static_assert(sizeof(TESAmmoExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESAmmoExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(TESAmmoExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(TESAmmoExtendedFormPrefixLayoutStorageLayout, component2) == 120, "independent target component offset");
// TESClass: EXE_RTTI
// Owner descriptor: .?AVTESClass@@
// Represented component at32: .?AVTESFullName@@
// Represented component at48: .?AVTESDescription@@
// Represented component at64: .?AVTESTexture@@
class TESClassExtendedFormPrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public DescriptionComponentLayout, public TextureComponentLayout {
public:
    TESClassExtendedFormPrefixLayout();
    ~TESClassExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESClassExtendedFormPrefixLayout) == 80, "represented initial component prefix only");
struct TESClassExtendedFormPrefixLayoutStorageLayout {
    FormHeaderLayout primary;
    FullNameComponentLayout component0;
    DescriptionComponentLayout component1;
    TextureComponentLayout component2;
};
static_assert(sizeof(TESClassExtendedFormPrefixLayoutStorageLayout) == 80, "physical prefix mirror");
static_assert(offsetof(TESClassExtendedFormPrefixLayoutStorageLayout, component0) == 32, "independent target component offset");
static_assert(offsetof(TESClassExtendedFormPrefixLayoutStorageLayout, component1) == 48, "independent target component offset");
static_assert(offsetof(TESClassExtendedFormPrefixLayoutStorageLayout, component2) == 64, "independent target component offset");
// TESFlora: EXE_RTTI
// Owner descriptor: .?AVTESFlora@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModelTextureSwap@@
// Represented component at120: .?AVBGSDestructibleObjectForm@@
class TESFloraExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public DestructibleComponentLayout {
public:
    TESFloraExtendedFormPrefixLayout();
    ~TESFloraExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESFloraExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct TESFloraExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelTextureSwapComponentLayout component1;
    DestructibleComponentLayout component2;
};
static_assert(sizeof(TESFloraExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESFloraExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(TESFloraExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(TESFloraExtendedFormPrefixLayoutStorageLayout, component2) == 120, "independent target component offset");
// TESFurniture: EXE_RTTI
// Owner descriptor: .?AVTESFurniture@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModelTextureSwap@@
// Represented component at120: .?AVBGSDestructibleObjectForm@@
class TESFurnitureExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public DestructibleComponentLayout {
public:
    TESFurnitureExtendedFormPrefixLayout();
    ~TESFurnitureExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESFurnitureExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct TESFurnitureExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelTextureSwapComponentLayout component1;
    DestructibleComponentLayout component2;
};
static_assert(sizeof(TESFurnitureExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESFurnitureExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(TESFurnitureExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(TESFurnitureExtendedFormPrefixLayoutStorageLayout, component2) == 120, "independent target component offset");
// TESKey: EXE_RTTI
// Owner descriptor: .?AVTESKey@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModelTextureSwap@@
// Represented component at120: .?AVTESIcon@@
class TESKeyExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout {
public:
    TESKeyExtendedFormPrefixLayout();
    ~TESKeyExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESKeyExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct TESKeyExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelTextureSwapComponentLayout component1;
    IconComponentLayout component2;
};
static_assert(sizeof(TESKeyExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESKeyExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(TESKeyExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(TESKeyExtendedFormPrefixLayoutStorageLayout, component2) == 120, "independent target component offset");
// TESObjectACTI: EXE_RTTI
// Owner descriptor: .?AVTESObjectACTI@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModelTextureSwap@@
// Represented component at120: .?AVBGSDestructibleObjectForm@@
class TESObjectACTIExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public DestructibleComponentLayout {
public:
    TESObjectACTIExtendedFormPrefixLayout();
    ~TESObjectACTIExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectACTIExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct TESObjectACTIExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelTextureSwapComponentLayout component1;
    DestructibleComponentLayout component2;
};
static_assert(sizeof(TESObjectACTIExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESObjectACTIExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(TESObjectACTIExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(TESObjectACTIExtendedFormPrefixLayoutStorageLayout, component2) == 120, "independent target component offset");
// TESObjectARMO: EXE_RTTI
// Owner descriptor: .?AVTESObjectARMO@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESRaceForm@@
// Represented component at80: .?AVTESEnchantableForm@@
// Represented component at104: .?AVTESValueForm@@
// Represented component at120: .?AVTESWeightForm@@
class TESObjectARMOExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public RaceComponentLayout, public EnchantableComponentLayout, public ValueComponentLayout, public WeightComponentLayout {
public:
    TESObjectARMOExtendedFormPrefixLayout();
    ~TESObjectARMOExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectARMOExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct TESObjectARMOExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    RaceComponentLayout component1;
    EnchantableComponentLayout component2;
    ValueComponentLayout component3;
    WeightComponentLayout component4;
};
static_assert(sizeof(TESObjectARMOExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESObjectARMOExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(TESObjectARMOExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(TESObjectARMOExtendedFormPrefixLayoutStorageLayout, component2) == 80, "independent target component offset");
static_assert(offsetof(TESObjectARMOExtendedFormPrefixLayoutStorageLayout, component3) == 104, "independent target component offset");
static_assert(offsetof(TESObjectARMOExtendedFormPrefixLayoutStorageLayout, component4) == 120, "independent target component offset");
// TESObjectBOOK: EXE_RTTI
// Owner descriptor: .?AVTESObjectBOOK@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModelTextureSwap@@
// Represented component at120: .?AVTESIcon@@
class TESObjectBOOKExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout {
public:
    TESObjectBOOKExtendedFormPrefixLayout();
    ~TESObjectBOOKExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectBOOKExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct TESObjectBOOKExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelTextureSwapComponentLayout component1;
    IconComponentLayout component2;
};
static_assert(sizeof(TESObjectBOOKExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESObjectBOOKExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(TESObjectBOOKExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(TESObjectBOOKExtendedFormPrefixLayoutStorageLayout, component2) == 120, "independent target component offset");
// TESObjectCONT: EXE_RTTI
// Owner descriptor: .?AVTESObjectCONT@@
// Represented component at48: .?AVTESContainer@@
// Represented component at72: .?AVTESFullName@@
// Represented component at88: .?AVTESModelTextureSwap@@
class TESObjectCONTExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public ContainerComponentLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout {
public:
    TESObjectCONTExtendedFormPrefixLayout();
    ~TESObjectCONTExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectCONTExtendedFormPrefixLayout) == 144, "represented initial component prefix only");
struct TESObjectCONTExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    ContainerComponentLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
};
static_assert(sizeof(TESObjectCONTExtendedFormPrefixLayoutStorageLayout) == 144, "physical prefix mirror");
static_assert(offsetof(TESObjectCONTExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(TESObjectCONTExtendedFormPrefixLayoutStorageLayout, component1) == 72, "independent target component offset");
static_assert(offsetof(TESObjectCONTExtendedFormPrefixLayoutStorageLayout, component2) == 88, "independent target component offset");
// TESObjectDOOR: EXE_RTTI
// Owner descriptor: .?AVTESObjectDOOR@@
// Represented component at48: .?AVTESFullName@@
// Represented component at64: .?AVTESModelTextureSwap@@
// Represented component at120: .?AVBGSDestructibleObjectForm@@
class TESObjectDOORExtendedFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public DestructibleComponentLayout {
public:
    TESObjectDOORExtendedFormPrefixLayout();
    ~TESObjectDOORExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectDOORExtendedFormPrefixLayout) == 136, "represented initial component prefix only");
struct TESObjectDOORExtendedFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout primary;
    FullNameComponentLayout component0;
    ModelTextureSwapComponentLayout component1;
    DestructibleComponentLayout component2;
};
static_assert(sizeof(TESObjectDOORExtendedFormPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(TESObjectDOORExtendedFormPrefixLayoutStorageLayout, component0) == 48, "independent target component offset");
static_assert(offsetof(TESObjectDOORExtendedFormPrefixLayoutStorageLayout, component1) == 64, "independent target component offset");
static_assert(offsetof(TESObjectDOORExtendedFormPrefixLayoutStorageLayout, component2) == 120, "independent target component offset");
// TESShout: EXE_RTTI
// Owner descriptor: .?AVTESShout@@
// Represented component at32: .?AVTESFullName@@
// Represented component at48: .?AVBGSMenuDisplayObject@@
// Represented component at64: .?AVBGSEquipType@@
// Represented component at80: .?AVTESDescription@@
class TESShoutExtendedFormPrefixLayout : public FormHeaderLayout, public FullNameComponentLayout, public MenuDisplayComponentLayout, public EquipTypeComponentLayout, public DescriptionComponentLayout {
public:
    TESShoutExtendedFormPrefixLayout();
    ~TESShoutExtendedFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESShoutExtendedFormPrefixLayout) == 96, "represented initial component prefix only");
struct TESShoutExtendedFormPrefixLayoutStorageLayout {
    FormHeaderLayout primary;
    FullNameComponentLayout component0;
    MenuDisplayComponentLayout component1;
    EquipTypeComponentLayout component2;
    DescriptionComponentLayout component3;
};
static_assert(sizeof(TESShoutExtendedFormPrefixLayoutStorageLayout) == 96, "physical prefix mirror");
static_assert(offsetof(TESShoutExtendedFormPrefixLayoutStorageLayout, component0) == 32, "independent target component offset");
static_assert(offsetof(TESShoutExtendedFormPrefixLayoutStorageLayout, component1) == 48, "independent target component offset");
static_assert(offsetof(TESShoutExtendedFormPrefixLayoutStorageLayout, component2) == 64, "independent target component offset");
static_assert(offsetof(TESShoutExtendedFormPrefixLayoutStorageLayout, component3) == 80, "independent target component offset");
}
