// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (pinned complete public data and independent target primary RTTI/call operands).
// Code origin: public data-only adaptations; ordinary compiler deleting wrappers, complete destructor bodies external. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{S/SettingCollection.h,S/SettingCollectionList.h,I/INISettingCollection.h,I/INIPrefSettingCollection.h,R/RegSettingCollection.h,B/BSShaderProperty.h,S/ShaderReferenceEffect.h,B/BSTArray.h,B/BSSoundHandle.h}; MIT.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/BSDistantTreeShaderProperty.h; GPL-3.0.
// SettingCollection, SettingCollectionList, INISettingCollection, INIPrefSettingCollection, RegSettingCollection, BSShaderProperty, ShaderReferenceEffect, RenderPassArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSDistantTreeShaderProperty: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// New storage names, member aliases and pointee names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "unmapped/represented/LayoutValueTypes.h"
#include "unmapped/represented/BSSoundHandleLayout.h"
#include "gamebryo/nimain/NiShadePropertyStorageLayout.h"
#include "unmapped/represented/ReferenceEffectLayout.h"
namespace ResearchLayouts {
class SettingPointeeStorageLayout;
class RenderPassPointeeStorageLayout;
class ShaderFadeNodePointeeLayout;
class EffectShaderDataPointeeLayout;
class ShaderLightDataPointeeLayout;
class ShaderMaterialPointeeLayout;
class EffectTextureRequestPointeeLayout;
class EffectParticleShaderPointeeLayout;
class EffectObjectPointeeLayout;
class EffectTexturePointeeLayout;
class EffectBoundObjectPointeeLayout;
class EffectShaderPointeeLayout;
class SettingCollectionDataStorageLayout {
public:
    virtual ~SettingCollectionDataStorageLayout();
    char subKey[260];
    void* handle;
};
class SettingListDataStorageLayout : public SettingCollectionDataStorageLayout {
public:
    ~SettingListDataStorageLayout() override;
    BSSimpleList<SettingPointeeStorageLayout*> settings;
};
class IniSettingsDataStorageLayout : public SettingListDataStorageLayout { public: ~IniSettingsDataStorageLayout() override; };
class IniPrefSettingsDataStorageLayout : public SettingListDataStorageLayout { public: ~IniPrefSettingsDataStorageLayout() override; };
class RegistrySettingsDataStorageLayout : public SettingListDataStorageLayout { public: ~RegistrySettingsDataStorageLayout() override; };
struct ShaderRenderPassArrayDataStorageLayout { RenderPassPointeeStorageLayout* head; };
class ShaderPropertyDataStorageLayout : public NiShadePropertyStorageLayout {
public:
    ~ShaderPropertyDataStorageLayout() override;
    float alpha;
    std::int32_t lastRenderPassState;
    std::uint64_t flags;
    ShaderRenderPassArrayDataStorageLayout renderPassList;
    std::uint64_t unk48;
    ShaderRenderPassArrayDataStorageLayout debugRenderPassList;
    std::uint64_t unk58;
    ShaderFadeNodePointeeLayout* fadeNode;
    EffectShaderDataPointeeLayout* effectData;
    ShaderLightDataPointeeLayout* lightData;
    ShaderMaterialPointeeLayout* material;
    std::uint64_t unk80;
};
class DistantTreeShaderDataStorageLayout : public ShaderPropertyDataStorageLayout {
public:
    ~DistantTreeShaderDataStorageLayout() override;
    std::uint32_t instanceCount,unk8C;
    std::uint64_t unk90,unk98,unkA0,unkA8;
};
class ShaderReferenceDataStorageLayout : public ReferenceEffectLayout {
public:
    ~ShaderReferenceDataStorageLayout() override;
    BSTArray<EffectTextureRequestPointeeLayout> textureRequests;
    BSTArray<EffectObjectPointeeLayout*> addonModels;
    BSTArray<void*> unk078;
    BSTArray<EffectParticleShaderPointeeLayout> particleShaders;
    BSTArray<void*> unk0A8;
    BSSoundHandleLayout soundHandle;
    EffectTexturePointeeLayout* particleShaderTexture;
    EffectTexturePointeeLayout* particlePaletteTexture;
    EffectTexturePointeeLayout* fillTexture;
    EffectTexturePointeeLayout* holesTexture;
    EffectTexturePointeeLayout* paletteTexture;
    EffectObjectPointeeLayout* lastRootNode;
    EffectBoundObjectPointeeLayout* wornObject;
    EffectShaderPointeeLayout* effectData;
    EffectShaderDataPointeeLayout* effectShaderData;
    EffectObjectPointeeLayout* targetRoot;
    float alphaTimer,addonAlpha,addonScale,effectShaderAge;
    std::uint32_t flags,pushCount;
};
static_assert(sizeof(SettingCollectionDataStorageLayout)==280,"complete pinned public data storage");
static_assert(sizeof(SettingListDataStorageLayout)==296,"complete pinned public data storage");
static_assert(sizeof(IniSettingsDataStorageLayout)==296,"complete pinned public data storage");
static_assert(sizeof(IniPrefSettingsDataStorageLayout)==296,"complete pinned public data storage");
static_assert(sizeof(RegistrySettingsDataStorageLayout)==296,"complete pinned public data storage");
static_assert(sizeof(ShaderRenderPassArrayDataStorageLayout)==8,"complete pinned public data storage");
static_assert(sizeof(ShaderPropertyDataStorageLayout)==136,"complete pinned public data storage");
static_assert(sizeof(DistantTreeShaderDataStorageLayout)==176,"complete pinned public data storage");
static_assert(sizeof(ShaderReferenceDataStorageLayout)==312,"complete pinned public data storage");
static_assert(offsetof(SettingCollectionDataStorageLayout,subKey)==8,"public field offset");
static_assert(offsetof(SettingCollectionDataStorageLayout,handle)==272,"public field offset");
static_assert(offsetof(SettingListDataStorageLayout,settings)==280,"public field offset");
static_assert(offsetof(ShaderRenderPassArrayDataStorageLayout,head)==0,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,alpha)==48,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,lastRenderPassState)==52,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,flags)==56,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,renderPassList)==64,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,unk48)==72,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,debugRenderPassList)==80,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,unk58)==88,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,fadeNode)==96,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,effectData)==104,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,lightData)==112,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,material)==120,"public field offset");
static_assert(offsetof(ShaderPropertyDataStorageLayout,unk80)==128,"public field offset");
static_assert(offsetof(DistantTreeShaderDataStorageLayout,instanceCount)==136,"public field offset");
static_assert(offsetof(DistantTreeShaderDataStorageLayout,unk8C)==140,"public field offset");
static_assert(offsetof(DistantTreeShaderDataStorageLayout,unk90)==144,"public field offset");
static_assert(offsetof(DistantTreeShaderDataStorageLayout,unk98)==152,"public field offset");
static_assert(offsetof(DistantTreeShaderDataStorageLayout,unkA0)==160,"public field offset");
static_assert(offsetof(DistantTreeShaderDataStorageLayout,unkA8)==168,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,textureRequests)==72,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,addonModels)==96,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,unk078)==120,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,particleShaders)==144,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,unk0A8)==168,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,soundHandle)==192,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,particleShaderTexture)==208,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,particlePaletteTexture)==216,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,fillTexture)==224,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,holesTexture)==232,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,paletteTexture)==240,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,lastRootNode)==248,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,wornObject)==256,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,effectData)==264,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,effectShaderData)==272,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,targetRoot)==280,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,alphaTimer)==288,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,addonAlpha)==292,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,addonScale)==296,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,effectShaderAge)==300,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,flags)==304,"public field offset");
static_assert(offsetof(ShaderReferenceDataStorageLayout,pushCount)==308,"public field offset");
static_assert(sizeof(((SettingCollectionDataStorageLayout*)0)->subKey)==260,"public character key extent");
}
