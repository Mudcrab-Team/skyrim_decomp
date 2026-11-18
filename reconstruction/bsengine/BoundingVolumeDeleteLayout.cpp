// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// BoundingVolumeDeleteLayout, BoxScalarDeleteLayout, CapsuleDeleteLayout, HalfSpaceDeleteLayout, SphereDeleteLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v9
// Code origin: value declarations adapted from CommonLibSSE-NG; bounding-volume, sphere, capsule and half-space declarations adapted from the authorized FNV sibling source. Box scalar declarations are originally inferred from target member accesses. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/N/NiPoint3.h, NiBound.h, NiPlane.h.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiBoundingVolume.h
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiSphereBV.h
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiCapsuleBV.h
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiHalfSpaceBV.h
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf38370 DeletingLeaff38370::~DeletingLeaff38370
void operator delete(void*, unsigned __int64) noexcept;
#include "BoundingVolumeDeleteLayout.h"
namespace ResearchLayouts {
inline BoundingVolumeDeleteLayout::~BoundingVolumeDeleteLayout() {}
inline BoxScalarDeleteLayout::~BoxScalarDeleteLayout() {}
inline CapsuleDeleteLayout::~CapsuleDeleteLayout() {}
inline HalfSpaceDeleteLayout::~HalfSpaceDeleteLayout() {}
inline SphereDeleteLayout::~SphereDeleteLayout() {}
}
static_assert(sizeof(ResearchLayouts::BoxScalarDeleteLayout) == 72, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CapsuleDeleteLayout) == 64, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HalfSpaceDeleteLayout) == 40, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::SphereDeleteLayout) == 24, "independently observed allocation size");
static ResearchLayouts::BoxScalarDeleteLayout object0;
static ResearchLayouts::CapsuleDeleteLayout object1;
static ResearchLayouts::HalfSpaceDeleteLayout object2;
static ResearchLayouts::SphereDeleteLayout object3;
