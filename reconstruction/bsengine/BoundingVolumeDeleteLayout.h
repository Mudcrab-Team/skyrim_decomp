// Source exposure: mixed (community and authorized sibling declarations, local binary analysis).
// Code origin: value declarations adapted from CommonLibSSE-NG; bounding-volume, sphere, capsule and half-space declarations adapted from the authorized FNV sibling source. Box scalar declarations are originally inferred from target member accesses. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/N/NiPoint3.h, NiBound.h, NiPlane.h.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiBoundingVolume.h
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiSphereBV.h
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiCapsuleBV.h
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiHalfSpaceBV.h
// BoundingVolumeDeleteLayout, SphereDeleteLayout, CapsuleDeleteLayout, HalfSpaceDeleteLayout: GUESS(low) STANDIN; represented aliases with incomplete virtual method sets.
// BoxScalarDeleteLayout, scalar08, scalar0C, scalar10, scalar14, scalar18, scalar1C, scalar20, scalar24, scalar28, scalar2C, scalar30, scalar34, scalar38, scalar3C, scalar40: GUESS(low) STANDIN; individually observed scalar floating-point accesses, no original field grouping claimed.
// center, radius, normal, constant, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// axisDirection, halfLength, segmentOrigin, segmentDirection, boundRadius, halfSpacePlane: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// DeletePoint3, DeleteSphere, DeletePlane, sphere: GUESS(medium) STANDIN; aliases for the cited value declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
namespace ResearchLayouts {
struct DeletePoint3 { float x; float y; float z; };
struct DeleteSphere { DeletePoint3 center; float radius; };
struct DeletePlane { DeletePoint3 normal; float constant; };
class BoundingVolumeDeleteLayout { public: virtual ~BoundingVolumeDeleteLayout(); };
class SphereDeleteLayout : public BoundingVolumeDeleteLayout { public: ~SphereDeleteLayout() override; DeleteSphere sphere; };
class CapsuleDeleteLayout : public BoundingVolumeDeleteLayout {
public:
    ~CapsuleDeleteLayout() override;
    DeletePoint3 center;
    DeletePoint3 axisDirection;
    float halfLength;
    DeletePoint3 segmentOrigin;
    DeletePoint3 segmentDirection;
    float boundRadius;
};
class HalfSpaceDeleteLayout : public BoundingVolumeDeleteLayout {
public:
    ~HalfSpaceDeleteLayout() override;
    DeletePlane halfSpacePlane;
    DeletePoint3 center;
};
class BoxScalarDeleteLayout : public BoundingVolumeDeleteLayout {
public:
    ~BoxScalarDeleteLayout() override;
    float scalar08;
    float scalar0C;
    float scalar10;
    float scalar14;
    float scalar18;
    float scalar1C;
    float scalar20;
    float scalar24;
    float scalar28;
    float scalar2C;
    float scalar30;
    float scalar34;
    float scalar38;
    float scalar3C;
    float scalar40;
};
static_assert(sizeof(DeletePoint3)==12, "three declared coordinates");
static_assert(sizeof(BoundingVolumeDeleteLayout)==8, "represented virtual interface");
static_assert(sizeof(SphereDeleteLayout)==24, "declared sphere");
static_assert(sizeof(CapsuleDeleteLayout)==64, "declared capsule");
static_assert(sizeof(HalfSpaceDeleteLayout)==40, "declared plane and center");
static_assert(sizeof(BoxScalarDeleteLayout)==72, "observed scalar members");
static_assert(offsetof(CapsuleDeleteLayout, center)==8, "center offset");
static_assert(offsetof(CapsuleDeleteLayout, axisDirection)==20, "axis offset");
static_assert(offsetof(CapsuleDeleteLayout, halfLength)==32, "length offset");
static_assert(offsetof(CapsuleDeleteLayout, segmentOrigin)==36, "segment origin offset");
static_assert(offsetof(CapsuleDeleteLayout, segmentDirection)==48, "segment direction offset");
static_assert(offsetof(CapsuleDeleteLayout, boundRadius)==60, "radius offset");
static_assert(offsetof(HalfSpaceDeleteLayout, halfSpacePlane)==8, "plane offset");
static_assert(offsetof(HalfSpaceDeleteLayout, center)==24, "center offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar08)==8, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar0C)==12, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar10)==16, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar14)==20, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar18)==24, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar1C)==28, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar20)==32, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar24)==36, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar28)==40, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar2C)==44, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar30)==48, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar34)==52, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar38)==56, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar3C)==60, "observed scalar offset");
static_assert(offsetof(BoxScalarDeleteLayout, scalar40)==64, "observed scalar offset");
}
