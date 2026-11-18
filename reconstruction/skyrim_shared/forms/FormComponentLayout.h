// Source exposure: mixed (pinned community component declarations; independent target RTTI and secondary-slot analysis).
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, include/RE/{B,T,N} component headers; MIT.
// BaseFormComponent, TESForm, TESObject, TESBoundObject, TESFullName, TESDescription, TESSpellList, BGSSkinForm, BGSBipedObjectForm, BGSKeywordForm, BGSAttackDataForm, TESModel, TESTexture, TESIcon, BGSPickupPutdownSounds, BGSPreloadable, TESImageSpaceModifiableForm, BGSDestructibleObjectForm, BSFixedString, BGSLocalizedStringDL, NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRace, BGSNote, BGSHazard, BGSProjectile: EXE_RTTI
// All ResearchLayouts class and struct names ending Layout, the physical storage wrappers and prefix mirror names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
namespace ResearchLayouts {
class TESFileArrayLayout;
class TESObjectARMOPointeeLayout;
class BGSKeywordPointeeLayout;
class BGSAttackDataMapPointeeLayout;
class SpellDataPointeeLayout;
class ResourceIDPointeeLayout;
class BGSSoundDescriptorPointeeLayout;
class TESImageSpaceModifierPointeeLayout;
class DestructibleObjectDataPointeeLayout;
struct FixedStringStorageLayout { const char* data; };
struct LocalizedStringStorageLayout { std::uint32_t id; };
template<class T> struct IntrusivePointerStorageLayout { T* pointer; };
struct SourceFilesStorageLayout { TESFileArrayLayout* array; };
class FormComponentLayout {
public:
    virtual ~FormComponentLayout();
    virtual void InitializeDataComponent() = 0;
    virtual void ClearDataComponent() = 0;
    virtual void CopyComponent(FormComponentLayout*) = 0;
};
class FormHeaderLayout : public FormComponentLayout {
public:
    ~FormHeaderLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    SourceFilesStorageLayout sourceFiles;
    std::uint32_t formFlags;
    std::uint32_t formID;
    std::uint16_t inGameFormFlags;
    std::uint8_t formType;
    std::uint8_t pad1B;
    std::uint32_t pad1C;
};
class ObjectFormHeaderLayout : public FormHeaderLayout { public: ~ObjectFormHeaderLayout() override; };
struct BoundPointLayout { std::int16_t x, y, z; };
struct BoundDataLayout { BoundPointLayout boundMin, boundMax; };
class BoundObjectFormHeaderLayout : public ObjectFormHeaderLayout {
public:
    ~BoundObjectFormHeaderLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    BoundDataLayout boundData;
    std::uint32_t pad2C;
};
class FullNameComponentLayout : public FormComponentLayout {
public:
    ~FullNameComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    FixedStringStorageLayout fullName;
};
class DescriptionComponentLayout : public FormComponentLayout {
public:
    ~DescriptionComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    std::uint32_t fileOffset;
    LocalizedStringStorageLayout descriptionText;
};
class SpellListComponentLayout : public FormComponentLayout {
public:
    ~SpellListComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    SpellDataPointeeLayout* actorEffects;
};
class SkinComponentLayout : public FormComponentLayout {
public:
    ~SkinComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    TESObjectARMOPointeeLayout* skin;
};
struct BipedModelStorageLayout { std::uint32_t bipedObjectSlots, armorType; };
class BipedComponentLayout : public FormComponentLayout {
public:
    ~BipedComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    BipedModelStorageLayout bipedModelData;
};
class KeywordComponentLayout : public FormComponentLayout {
public:
    ~KeywordComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    BGSKeywordPointeeLayout** keywords;
    std::uint32_t numKeywords;
    std::uint32_t pad14;
};
class AttackDataComponentLayout : public FormComponentLayout {
public:
    ~AttackDataComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    IntrusivePointerStorageLayout<BGSAttackDataMapPointeeLayout> attackDataMap;
};
class ModelComponentLayout : public FormComponentLayout {
public:
    ~ModelComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    FixedStringStorageLayout model;
    ResourceIDPointeeLayout* textures;
    std::uint32_t* addons;
    std::uint16_t numTextures;
    std::uint16_t numAddons;
    std::uint32_t pad24;
};
class TextureComponentLayout : public FormComponentLayout {
public:
    ~TextureComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    FixedStringStorageLayout textureName;
};
class IconComponentLayout : public TextureComponentLayout { public: ~IconComponentLayout() override; };
class PickupSoundsComponentLayout : public FormComponentLayout {
public:
    ~PickupSoundsComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    BGSSoundDescriptorPointeeLayout* pickupSound;
    BGSSoundDescriptorPointeeLayout* putdownSound;
};
class PreloadableComponentLayout : public FormComponentLayout {
public:
    ~PreloadableComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    virtual void Unk_04() = 0;
};
class ImageSpaceComponentLayout : public FormComponentLayout {
public:
    ~ImageSpaceComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    TESImageSpaceModifierPointeeLayout* imageSpaceModifying;
};
class DestructibleComponentLayout : public FormComponentLayout {
public:
    ~DestructibleComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    DestructibleObjectDataPointeeLayout* data;
};
static_assert(sizeof(FormComponentLayout) == 8, "pinned community component storage");
static_assert(sizeof(FormHeaderLayout) == 32, "pinned community component storage");
static_assert(sizeof(ObjectFormHeaderLayout) == 32, "pinned community component storage");
static_assert(sizeof(BoundPointLayout) == 6, "pinned community component storage");
static_assert(sizeof(BoundDataLayout) == 12, "pinned community component storage");
static_assert(sizeof(BoundObjectFormHeaderLayout) == 48, "pinned community component storage");
static_assert(sizeof(FullNameComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(DescriptionComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(SpellListComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(SkinComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(BipedModelStorageLayout) == 8, "pinned community component storage");
static_assert(sizeof(BipedComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(KeywordComponentLayout) == 24, "pinned community component storage");
static_assert(sizeof(AttackDataComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(ModelComponentLayout) == 40, "pinned community component storage");
static_assert(sizeof(TextureComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(IconComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(PickupSoundsComponentLayout) == 24, "pinned community component storage");
static_assert(sizeof(PreloadableComponentLayout) == 8, "pinned community component storage");
static_assert(sizeof(ImageSpaceComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(DestructibleComponentLayout) == 16, "pinned community component storage");
static_assert(sizeof(FixedStringStorageLayout) == 8, "pinned community component storage");
static_assert(sizeof(LocalizedStringStorageLayout) == 4, "pinned community component storage");
static_assert(sizeof(SourceFilesStorageLayout) == 8, "pinned community component storage");
static_assert(sizeof(IntrusivePointerStorageLayout<void>) == 8, "community pointer storage");
static_assert(offsetof(IntrusivePointerStorageLayout<void>, pointer) == 0, "community pointer offset");
static_assert(offsetof(FormHeaderLayout, sourceFiles) == 8, "pinned community member offset");
static_assert(offsetof(FormHeaderLayout, formFlags) == 16, "pinned community member offset");
static_assert(offsetof(FormHeaderLayout, formID) == 20, "pinned community member offset");
static_assert(offsetof(FormHeaderLayout, inGameFormFlags) == 24, "pinned community member offset");
static_assert(offsetof(FormHeaderLayout, formType) == 26, "pinned community member offset");
static_assert(offsetof(FormHeaderLayout, pad1B) == 27, "pinned community member offset");
static_assert(offsetof(FormHeaderLayout, pad1C) == 28, "pinned community member offset");
static_assert(offsetof(BoundObjectFormHeaderLayout, boundData) == 32, "pinned community member offset");
static_assert(offsetof(BoundObjectFormHeaderLayout, pad2C) == 44, "pinned community member offset");
static_assert(offsetof(FullNameComponentLayout, fullName) == 8, "pinned community member offset");
static_assert(offsetof(DescriptionComponentLayout, fileOffset) == 8, "pinned community member offset");
static_assert(offsetof(DescriptionComponentLayout, descriptionText) == 12, "pinned community member offset");
static_assert(offsetof(SpellListComponentLayout, actorEffects) == 8, "pinned community member offset");
static_assert(offsetof(SkinComponentLayout, skin) == 8, "pinned community member offset");
static_assert(offsetof(BipedComponentLayout, bipedModelData) == 8, "pinned community member offset");
static_assert(offsetof(KeywordComponentLayout, keywords) == 8, "pinned community member offset");
static_assert(offsetof(KeywordComponentLayout, numKeywords) == 16, "pinned community member offset");
static_assert(offsetof(KeywordComponentLayout, pad14) == 20, "pinned community member offset");
static_assert(offsetof(AttackDataComponentLayout, attackDataMap) == 8, "pinned community member offset");
static_assert(offsetof(ModelComponentLayout, model) == 8, "pinned community member offset");
static_assert(offsetof(ModelComponentLayout, textures) == 16, "pinned community member offset");
static_assert(offsetof(ModelComponentLayout, addons) == 24, "pinned community member offset");
static_assert(offsetof(ModelComponentLayout, numTextures) == 32, "pinned community member offset");
static_assert(offsetof(ModelComponentLayout, numAddons) == 34, "pinned community member offset");
static_assert(offsetof(ModelComponentLayout, pad24) == 36, "pinned community member offset");
static_assert(offsetof(TextureComponentLayout, textureName) == 8, "pinned community member offset");
static_assert(offsetof(PickupSoundsComponentLayout, pickupSound) == 8, "pinned community member offset");
static_assert(offsetof(PickupSoundsComponentLayout, putdownSound) == 16, "pinned community member offset");
static_assert(offsetof(ImageSpaceComponentLayout, imageSpaceModifying) == 8, "pinned community member offset");
static_assert(offsetof(DestructibleComponentLayout, data) == 8, "pinned community member offset");
static_assert(offsetof(FixedStringStorageLayout, data) == 0, "pinned community member offset");
static_assert(offsetof(LocalizedStringStorageLayout, id) == 0, "pinned community member offset");
static_assert(offsetof(SourceFilesStorageLayout, array) == 0, "pinned community member offset");
static_assert(offsetof(BoundDataLayout, boundMin) == 0, "pinned community member offset");
static_assert(offsetof(BoundDataLayout, boundMax) == 6, "pinned community member offset");
static_assert(offsetof(BoundPointLayout, x) == 0, "pinned community member offset");
static_assert(offsetof(BoundPointLayout, y) == 2, "pinned community member offset");
static_assert(offsetof(BoundPointLayout, z) == 4, "pinned community member offset");
static_assert(offsetof(BipedModelStorageLayout, bipedObjectSlots) == 0, "pinned community member offset");
static_assert(offsetof(BipedModelStorageLayout, armorType) == 4, "pinned community member offset");
struct PreloadableVptrStorageLayout { const void* const* dispatchTable; };
static_assert(sizeof(PreloadableVptrStorageLayout) == sizeof(PreloadableComponentLayout), "fieldless preloadable mirror");
static_assert(offsetof(PreloadableVptrStorageLayout, dispatchTable) == 0, "primary vptr");
}
