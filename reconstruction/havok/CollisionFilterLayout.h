// Source exposure: mixed (pinned community and permitted FNV sibling declarations; independent target RTTI/slot/transfer analysis).
// Code origin: adapted declarations and original narrowed owner-prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/H/{hkBaseObject,hkReferencedObject,hkpCollisionFilter,hkpCollidableCollidableFilter,hkpShapeCollectionFilter,hkpRayShapeCollectionFilter,hkpRayCollidableFilter,hkpEntityListener}.h; MIT.
// Declaration source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/hkpConstraintListener.h; maintainer permission.
// hkBaseObject, hkReferencedObject, hkpCollisionFilter, hkpCollidableCollidableFilter, hkpShapeCollectionFilter, hkpRayShapeCollectionFilter, hkpRayCollidableFilter, hkpEntityListener: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// memSizeAndFlags, referenceCount, pad0C, pad30, pad34, type, pad3C, pad40, pad44, GetClassType, CalcContentStatistics, IsCollisionEnabled, NumShapeKeyHitsLimitBreached, Init, EntityAddedCallback, EntityRemovedCallback, EntityShapeSetCallback, EntitySetMotionTypeCallback, EntityDeletedCallback: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// hkpConstraintListener, ConstraintAddedCallback, ConstraintRemovedCallback: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// All ResearchLayouts class/struct names ending Layout and PrefixLayout and forward-declared type spellings: GUESS(medium) STANDIN
// hkpConstrainedSystemFilter, hkpConstraintCollisionFilter, hkpDisableEntityCollisionFilter, hkpCollisionFilterList, hkpGroupCollisionFilter, hkpGroupFilter, hkpNullCollisionFilter, hkpPairCollisionFilter, bhkCollisionFilter, Clear1nTracksFilter, NeverCollideFilter: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
namespace ResearchLayouts {
class HkClassLayout;
class HkStatisticsCollectorLayout;
class CollidableLayout;
class CollisionInputLayout;
class CollisionBodyLayout;
class ShapeContainerLayout;
class BvTreeShapeLayout;
class AabbLayout;
class ShapeRayCastInputLayout;
class WorldRayCastInputLayout;
class PhysicsWorldLayout;
class EntityLayout;
class ConstraintInstanceLayout;
class BaseObjectLayout { public: virtual ~BaseObjectLayout(); };
class ReferencedObjectLayout : public BaseObjectLayout {
public:
    ~ReferencedObjectLayout() override;
    virtual const HkClassLayout* GetClassType() const;
    virtual void CalcContentStatistics(HkStatisticsCollectorLayout*, const HkClassLayout*) const;
    std::uint16_t memSizeAndFlags;
    volatile mutable std::int16_t referenceCount;
    std::uint32_t pad0C;
};
class CollidableFilterLayout {
public:
    virtual ~CollidableFilterLayout();
    virtual bool IsCollisionEnabled(const CollidableLayout&, const CollidableLayout&) const = 0;
};
class ShapeCollectionFilterLayout {
public:
    virtual bool IsCollisionEnabled1(const CollisionInputLayout&, const CollisionBodyLayout&, const CollisionBodyLayout&, const ShapeContainerLayout&, std::uint32_t) const = 0;
    virtual bool IsCollisionEnabled2(const CollisionInputLayout&, const CollisionBodyLayout&, const CollisionBodyLayout&, const ShapeContainerLayout&, const ShapeContainerLayout&, std::uint32_t, std::uint32_t) const = 0;
    virtual std::int32_t NumShapeKeyHitsLimitBreached(const CollisionInputLayout&, const CollisionBodyLayout&, const CollisionBodyLayout&, const BvTreeShapeLayout*, AabbLayout&, std::uint32_t*, std::int32_t) const = 0;
    virtual ~ShapeCollectionFilterLayout();
};
class RayShapeCollectionFilterLayout {
public:
    virtual bool IsCollisionEnabled(const ShapeRayCastInputLayout&, const ShapeContainerLayout&, std::uint32_t) const = 0;
    virtual ~RayShapeCollectionFilterLayout();
};
class RayCollidableFilterLayout {
public:
    virtual ~RayCollidableFilterLayout();
    virtual bool IsCollisionEnabled(const WorldRayCastInputLayout&, const CollidableLayout&) const = 0;
};
class CollisionFilterLayout : public ReferencedObjectLayout, public CollidableFilterLayout, public ShapeCollectionFilterLayout, public RayShapeCollectionFilterLayout, public RayCollidableFilterLayout {
public:
    CollisionFilterLayout();
    ~CollisionFilterLayout() override;
    virtual void Init(PhysicsWorldLayout*);
    std::int32_t NumShapeKeyHitsLimitBreached(const CollisionInputLayout&, const CollisionBodyLayout&, const CollisionBodyLayout&, const BvTreeShapeLayout*, AabbLayout&, std::uint32_t*, std::int32_t) const override;
    std::uint32_t pad30;
    std::uint32_t pad34;
    std::uint32_t type;
    std::uint32_t pad3C;
    std::uint32_t pad40;
    std::uint32_t pad44;
};
class ConstraintListenerLayout {
public:
    virtual ~ConstraintListenerLayout();
    virtual void ConstraintAddedCallback(ConstraintInstanceLayout*);
    virtual void ConstraintRemovedCallback(ConstraintInstanceLayout*);
};
class EntityListenerLayout {
public:
    virtual ~EntityListenerLayout();
    virtual void EntityAddedCallback(EntityLayout*);
    virtual void EntityRemovedCallback(EntityLayout*);
    virtual void EntityShapeSetCallback(EntityLayout*);
    virtual void EntitySetMotionTypeCallback(EntityLayout*);
    virtual void EntityDeletedCallback(EntityLayout*);
};
struct CollisionFilterStorageLayout {
    const void* const* primary;
    std::uint16_t memSizeAndFlags;
    volatile std::int16_t referenceCount;
    std::uint32_t pad0C;
    const void* const* collidable;
    const void* const* shapeCollection;
    const void* const* rayShapeCollection;
    const void* const* rayCollidable;
    std::uint32_t pad30, pad34, type, pad3C, pad40, pad44;
};
struct CollisionFilterListenerStorageLayout {
    CollisionFilterStorageLayout collision;
    const void* const* listener;
};
static_assert(sizeof(BaseObjectLayout) == 8, "represented public/sibling contract size");
static_assert(sizeof(ReferencedObjectLayout) == 16, "represented public/sibling contract size");
static_assert(sizeof(CollidableFilterLayout) == 8, "represented public/sibling contract size");
static_assert(sizeof(ShapeCollectionFilterLayout) == 8, "represented public/sibling contract size");
static_assert(sizeof(RayShapeCollectionFilterLayout) == 8, "represented public/sibling contract size");
static_assert(sizeof(RayCollidableFilterLayout) == 8, "represented public/sibling contract size");
static_assert(sizeof(CollisionFilterLayout) == 72, "represented public/sibling contract size");
static_assert(sizeof(ConstraintListenerLayout) == 8, "represented public/sibling contract size");
static_assert(sizeof(EntityListenerLayout) == 8, "represented public/sibling contract size");
static_assert(sizeof(CollisionFilterStorageLayout) == 72, "represented public/sibling contract size");
static_assert(sizeof(CollisionFilterListenerStorageLayout) == 80, "represented public/sibling contract size");
static_assert(offsetof(ReferencedObjectLayout, memSizeAndFlags) == 8, "represented member/subobject offset");
static_assert(offsetof(ReferencedObjectLayout, referenceCount) == 10, "represented member/subobject offset");
static_assert(offsetof(ReferencedObjectLayout, pad0C) == 12, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterLayout, pad30) == 48, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterLayout, pad34) == 52, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterLayout, type) == 56, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterLayout, pad3C) == 60, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterLayout, pad40) == 64, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterLayout, pad44) == 68, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, primary) == 0, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, memSizeAndFlags) == 8, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, referenceCount) == 10, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, pad0C) == 12, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, collidable) == 16, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, shapeCollection) == 24, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, rayShapeCollection) == 32, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, rayCollidable) == 40, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, pad30) == 48, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, pad34) == 52, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, type) == 56, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, pad3C) == 60, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, pad40) == 64, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterStorageLayout, pad44) == 68, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterListenerStorageLayout, collision) == 0, "represented member/subobject offset");
static_assert(offsetof(CollisionFilterListenerStorageLayout, listener) == 72, "represented member/subobject offset");
// ClearOneTracksFilterPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVClear1nTracksFilter@?A0x422024b4@@
class ClearOneTracksFilterPrefixLayout : public CollisionFilterLayout {
public:
    ClearOneTracksFilterPrefixLayout();
    ~ClearOneTracksFilterPrefixLayout() override;
};
static_assert(sizeof(ClearOneTracksFilterPrefixLayout) == 72, "represented collision/listener prefix only");
// NeverCollideFilterPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVNeverCollideFilter@?A0x422024b4@@
class NeverCollideFilterPrefixLayout : public CollisionFilterLayout {
public:
    NeverCollideFilterPrefixLayout();
    ~NeverCollideFilterPrefixLayout() override;
};
static_assert(sizeof(NeverCollideFilterPrefixLayout) == 72, "represented collision/listener prefix only");
// BhkCollisionFilterPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVbhkCollisionFilter@@
class BhkCollisionFilterPrefixLayout : public CollisionFilterLayout {
public:
    BhkCollisionFilterPrefixLayout();
    ~BhkCollisionFilterPrefixLayout() override;
};
static_assert(sizeof(BhkCollisionFilterPrefixLayout) == 72, "represented collision/listener prefix only");
// CollisionFilterListPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVhkpCollisionFilterList@@
class CollisionFilterListPrefixLayout : public CollisionFilterLayout {
public:
    CollisionFilterListPrefixLayout();
    ~CollisionFilterListPrefixLayout() override;
};
static_assert(sizeof(CollisionFilterListPrefixLayout) == 72, "represented collision/listener prefix only");
// ConstrainedSystemFilterPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVhkpConstrainedSystemFilter@@
class ConstrainedSystemFilterPrefixLayout : public CollisionFilterLayout, public ConstraintListenerLayout {
public:
    ConstrainedSystemFilterPrefixLayout();
    ~ConstrainedSystemFilterPrefixLayout() override;
};
static_assert(sizeof(ConstrainedSystemFilterPrefixLayout) == 80, "represented collision/listener prefix only");
// ConstraintCollisionFilterPrimaryPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVhkpConstraintCollisionFilter@@
class ConstraintCollisionFilterPrimaryPrefixLayout : public CollisionFilterLayout {
public:
    ConstraintCollisionFilterPrimaryPrefixLayout();
    ~ConstraintCollisionFilterPrimaryPrefixLayout() override;
};
static_assert(sizeof(ConstraintCollisionFilterPrimaryPrefixLayout) == 72, "represented collision/listener prefix only");
// DisableEntityCollisionFilterPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVhkpDisableEntityCollisionFilter@@
class DisableEntityCollisionFilterPrefixLayout : public CollisionFilterLayout, public EntityListenerLayout {
public:
    DisableEntityCollisionFilterPrefixLayout();
    ~DisableEntityCollisionFilterPrefixLayout() override;
};
static_assert(sizeof(DisableEntityCollisionFilterPrefixLayout) == 80, "represented collision/listener prefix only");
// GroupCollisionFilterPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVhkpGroupCollisionFilter@@
class GroupCollisionFilterPrefixLayout : public CollisionFilterLayout {
public:
    GroupCollisionFilterPrefixLayout();
    ~GroupCollisionFilterPrefixLayout() override;
};
static_assert(sizeof(GroupCollisionFilterPrefixLayout) == 72, "represented collision/listener prefix only");
// GroupFilterPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVhkpGroupFilter@@
class GroupFilterPrefixLayout : public CollisionFilterLayout {
public:
    GroupFilterPrefixLayout();
    ~GroupFilterPrefixLayout() override;
};
static_assert(sizeof(GroupFilterPrefixLayout) == 72, "represented collision/listener prefix only");
// NullCollisionFilterPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVhkpNullCollisionFilter@@
class NullCollisionFilterPrefixLayout : public CollisionFilterLayout {
public:
    NullCollisionFilterPrefixLayout();
    ~NullCollisionFilterPrefixLayout() override;
};
static_assert(sizeof(NullCollisionFilterPrefixLayout) == 72, "represented collision/listener prefix only");
// PairCollisionFilterPrimaryPrefixLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVhkpPairCollisionFilter@@
class PairCollisionFilterPrimaryPrefixLayout : public CollisionFilterLayout {
public:
    PairCollisionFilterPrimaryPrefixLayout();
    ~PairCollisionFilterPrimaryPrefixLayout() override;
};
static_assert(sizeof(PairCollisionFilterPrimaryPrefixLayout) == 72, "represented collision/listener prefix only");
}
