// Source exposure: mixed (pinned community data storage and independent target field-operation/subobject analysis).
// Code origin: adapted community storage declarations, existing original represented-field template bodies and a defaulted owner constructor. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/TESObjectREFR.h,B/BGSBodyPartData.h,B/BGSBodyPartDefs.h,H/hkpCharacterProxy.h,H/hkArray.h,H/hkVector4.h,N/NonActorMagicTarget.h,B/BSExtraData.h,M/MagicTarget.h,B/BSTList.h}; MIT.
// TESObjectREFR, OBJ_REFR, BGSBodyPartData, hkpCharacterProxy, hkArray, hkVector4, NonActorMagicTarget, BSExtraData, MagicTarget, BSSimpleList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, storage-only member names and physical views: GUESS(medium) STANDIN
// Explosion ownership hint: GUESS(low) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "../bsengine/AdditionalInterfacePrefixLayout.h"
namespace ResearchLayouts {
class BodyPartPointeeLayout;
class RagdollPointeeLayout;
class RootCdPointPointeeLayout;
class RigidBodyPointeeLayout;
class PhantomPointeeLayout;
class TriggerVolumePointeeLayout;
class SpellDispelDataPointeeLayout;
class ActiveEffectPointeeLayout;
class FieldRecoveryStorageLayout : public TESObjectREFRComponentPrefixLayout {
public:
    BoundObjectFormHeaderLayout* baseObject;
};
struct BodyPartPointerArrayStorageLayout { BodyPartPointeeLayout* values[6]; };
class BodyPartDataFieldStorageLayout : public BGSBodyPartDataExtendedFormPrefixLayout {
public:
    BodyPartPointerArrayStorageLayout parts;
    RagdollPointeeLayout* ragdoll;
};
template<class T> struct HavokArrayStorageLayout {
    T* _data;
    std::int32_t _size;
    std::int32_t _capacityAndFlags;
};
// The public hkVector4 SIMD storage requires16-byte alignment; components here are a storage view only.
struct alignas(16) HavokVectorStorageLayout { float x, y, z, w; };
class CharacterProxyFieldStorageLayout : public HavokReferencePrefixLayout, public AdditionalInterfacePrefixLayout<3000>, public AdditionalInterfacePrefixLayout<3001> {
public:
    HavokArrayStorageLayout<RootCdPointPointeeLayout> manifold;
    HavokArrayStorageLayout<RigidBodyPointeeLayout*> bodies;
    HavokArrayStorageLayout<PhantomPointeeLayout*> phantoms;
    HavokArrayStorageLayout<TriggerVolumePointeeLayout*> overlappingTriggerVolumes;
    HavokVectorStorageLayout velocity;
};
class ExtraDataStoragePrefixLayout {
public:
    virtual ~ExtraDataStoragePrefixLayout();
    ExtraDataStoragePrefixLayout* next;
};
class MagicTargetStorageLayout {
public:
    virtual ~MagicTargetStorageLayout();
    SpellDispelDataPointeeLayout* postUpdateDispelList;
    std::uint8_t flags;
};
struct ActiveEffectListStorageLayout {
    ActiveEffectPointeeLayout* item;
    ActiveEffectListStorageLayout* next;
};
class NonActorMagicTargetRecoveredLayout : public ExtraDataStoragePrefixLayout, public MagicTargetStorageLayout {
public:
    NonActorMagicTargetRecoveredLayout();
    ~NonActorMagicTargetRecoveredLayout() override;
    TESObjectREFRComponentPrefixLayout* targetObject;
    ActiveEffectListStorageLayout activeEffects;
};
class NonActorMagicTargetSecondaryStorageLayout : public MagicTargetStorageLayout {
public:
    TESObjectREFRComponentPrefixLayout* targetObject;
    ActiveEffectListStorageLayout activeEffects;
};
static_assert(sizeof(FieldRecoveryStorageLayout) == 72, "reference first-data-pointer prefix only");
static_assert(offsetof(FieldRecoveryStorageLayout, baseObject) == 64, "public OBJ_REFR first pointer offset");
static_assert(sizeof(BodyPartPointerArrayStorageLayout) == 48, "public six body-part pointers");
static_assert(sizeof(BodyPartDataFieldStorageLayout) == 136, "pinned public body-part data storage");
static_assert(offsetof(BodyPartDataFieldStorageLayout, parts) == 80, "public body-part array offset");
static_assert(offsetof(BodyPartDataFieldStorageLayout, ragdoll) == 128, "public ragdoll pointer offset");
static_assert(sizeof(HavokArrayStorageLayout<void*>) == 16, "public Havok array storage");
static_assert(offsetof(HavokArrayStorageLayout<void*>, _size) == 8, "public array size offset");
static_assert(offsetof(HavokArrayStorageLayout<void*>, _capacityAndFlags) == 12, "public capacity flags offset");
static_assert(sizeof(HavokVectorStorageLayout) == 16, "public four-float SIMD storage");
static_assert(alignof(HavokVectorStorageLayout) == 16, "public SIMD alignment");
static_assert(sizeof(CharacterProxyFieldStorageLayout) == 112, "represented proxy prefix through velocity");
static_assert(offsetof(CharacterProxyFieldStorageLayout, manifold) == 32, "public manifold array offset");
static_assert(offsetof(CharacterProxyFieldStorageLayout, bodies) == 48, "public bodies array offset");
static_assert(offsetof(CharacterProxyFieldStorageLayout, phantoms) == 64, "public phantoms array offset");
static_assert(offsetof(CharacterProxyFieldStorageLayout, overlappingTriggerVolumes) == 80, "public trigger array offset");
static_assert(offsetof(CharacterProxyFieldStorageLayout, velocity) == 96, "public vector offset");
static_assert(sizeof(ExtraDataStoragePrefixLayout) == 16, "public extra-data storage");
static_assert(offsetof(ExtraDataStoragePrefixLayout, next) == 8, "public extra-data link offset");
static_assert(sizeof(MagicTargetStorageLayout) == 24, "public magic target storage");
static_assert(offsetof(MagicTargetStorageLayout, postUpdateDispelList) == 8, "public dispel pointer offset");
static_assert(offsetof(MagicTargetStorageLayout, flags) == 16, "public target flags offset");
static_assert(sizeof(ActiveEffectListStorageLayout) == 16, "public inline list-head storage");
static_assert(offsetof(ActiveEffectListStorageLayout, next) == 8, "public list next pointer offset");
static_assert(sizeof(NonActorMagicTargetRecoveredLayout) == 64, "public non-actor magic target storage");
static_assert(offsetof(NonActorMagicTargetRecoveredLayout, targetObject) == 40, "public absolute target pointer offset");
static_assert(offsetof(NonActorMagicTargetRecoveredLayout, activeEffects) == 48, "public absolute active list offset");
static_assert(sizeof(NonActorMagicTargetSecondaryStorageLayout) == 48, "represented secondary subobject storage view");
static_assert(offsetof(NonActorMagicTargetSecondaryStorageLayout, targetObject) == 24, "target secondary-relative pointer offset");
static_assert(offsetof(NonActorMagicTargetSecondaryStorageLayout, activeEffects) == 32, "target secondary-relative inline list offset");
}
