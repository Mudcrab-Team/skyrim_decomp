// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: OcclusionShapePtr::~OcclusionShapePtr, treated as adapted: it has the shape of NiPointer::~NiPointer, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0x18f5a0 ??_GExtraOcclusionShape@@UEAAPEAXI@Z
// 0x18f5a0 ExtraOcclusionShape::~ExtraOcclusionShape
#include "ExtraOcclusionShape_18f5a0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
// The CrashLogger name dtor_deleting is this class's compiler-generated deleting destructor.
ExtraOcclusionShape::ExtraOcclusionShape() = default;
