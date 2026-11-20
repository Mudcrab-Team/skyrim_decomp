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
// 0x10a5d2c ClearOneTracksFilterPrefixLayout secondary destructor adjustor
// 0x10a5d38 ClearOneTracksFilterPrefixLayout secondary destructor adjustor
// 0x10a5d44 ClearOneTracksFilterPrefixLayout secondary destructor adjustor
// 0x10a5d50 ClearOneTracksFilterPrefixLayout secondary destructor adjustor
// 0x10a5d5c NeverCollideFilterPrefixLayout secondary destructor adjustor
// 0x10a5d68 NeverCollideFilterPrefixLayout secondary destructor adjustor
// 0x10a5d74 NeverCollideFilterPrefixLayout secondary destructor adjustor
// 0x10a5d80 NeverCollideFilterPrefixLayout secondary destructor adjustor
// 0x107f2c8 BhkCollisionFilterPrefixLayout secondary destructor adjustor
// 0x107f2d4 BhkCollisionFilterPrefixLayout secondary destructor adjustor
// 0x107f2e0 BhkCollisionFilterPrefixLayout secondary destructor adjustor
// 0x107f2ec BhkCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb3cdf8 CollisionFilterLayout secondary destructor adjustor
// 0xb3ce04 CollisionFilterLayout secondary destructor adjustor
// 0xb3ce10 CollisionFilterLayout secondary destructor adjustor
// 0xb3ce1c CollisionFilterLayout secondary destructor adjustor
// 0xb3db2c CollisionFilterListPrefixLayout secondary destructor adjustor
// 0xb3db38 CollisionFilterListPrefixLayout secondary destructor adjustor
// 0xb3db44 CollisionFilterListPrefixLayout secondary destructor adjustor
// 0xb3db50 CollisionFilterListPrefixLayout secondary destructor adjustor
// 0xb9bc54 ConstrainedSystemFilterPrefixLayout secondary destructor adjustor
// 0xb9bc60 ConstrainedSystemFilterPrefixLayout secondary destructor adjustor
// 0xb9bc6c ConstrainedSystemFilterPrefixLayout secondary destructor adjustor
// 0xb9bc78 ConstrainedSystemFilterPrefixLayout secondary destructor adjustor
// 0xb9bc84 ConstrainedSystemFilterPrefixLayout secondary destructor adjustor
// 0xb51884 ConstraintCollisionFilterPrimaryPrefixLayout secondary destructor adjustor
// 0xb51890 ConstraintCollisionFilterPrimaryPrefixLayout secondary destructor adjustor
// 0xb5189c ConstraintCollisionFilterPrimaryPrefixLayout secondary destructor adjustor
// 0xb518a8 ConstraintCollisionFilterPrimaryPrefixLayout secondary destructor adjustor
// 0xb9bc90 DisableEntityCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb9bc9c DisableEntityCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb9bca8 DisableEntityCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb9bcb4 DisableEntityCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb9bcc0 DisableEntityCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb9bccc GroupCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb9bcd8 GroupCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb9bce4 GroupCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb9bcf0 GroupCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb3c4f4 GroupFilterPrefixLayout secondary destructor adjustor
// 0xb3c500 GroupFilterPrefixLayout secondary destructor adjustor
// 0xb3c50c GroupFilterPrefixLayout secondary destructor adjustor
// 0xb3c518 GroupFilterPrefixLayout secondary destructor adjustor
// 0xb364fc NullCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb36508 NullCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb36514 NullCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb36520 NullCollisionFilterPrefixLayout secondary destructor adjustor
// 0xb518c0 PairCollisionFilterPrimaryPrefixLayout secondary destructor adjustor
// 0xb518cc PairCollisionFilterPrimaryPrefixLayout secondary destructor adjustor
// 0xb518d8 PairCollisionFilterPrimaryPrefixLayout secondary destructor adjustor
// 0xb518e4 PairCollisionFilterPrimaryPrefixLayout secondary destructor adjustor
#include "CollisionFilterLayout.h"
namespace ResearchLayouts {
ClearOneTracksFilterPrefixLayout::ClearOneTracksFilterPrefixLayout() = default;
NeverCollideFilterPrefixLayout::NeverCollideFilterPrefixLayout() = default;
BhkCollisionFilterPrefixLayout::BhkCollisionFilterPrefixLayout() = default;
CollisionFilterLayout::CollisionFilterLayout() = default;
CollisionFilterListPrefixLayout::CollisionFilterListPrefixLayout() = default;
ConstrainedSystemFilterPrefixLayout::ConstrainedSystemFilterPrefixLayout() = default;
ConstraintCollisionFilterPrimaryPrefixLayout::ConstraintCollisionFilterPrimaryPrefixLayout() = default;
DisableEntityCollisionFilterPrefixLayout::DisableEntityCollisionFilterPrefixLayout() = default;
GroupCollisionFilterPrefixLayout::GroupCollisionFilterPrefixLayout() = default;
GroupFilterPrefixLayout::GroupFilterPrefixLayout() = default;
NullCollisionFilterPrefixLayout::NullCollisionFilterPrefixLayout() = default;
PairCollisionFilterPrimaryPrefixLayout::PairCollisionFilterPrimaryPrefixLayout() = default;
}
