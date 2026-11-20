// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaAnimation; size 0x38
#pragma once

#include "AnimationType.h"
#include "hkArray_RE__hkaAnnotationTrack_520f07a1.h"
#include "hkRefPtr_RE__hkaAnimatedReferenceFrame_41cd4124.h"
#include "hkReferencedObject.h"
struct hkaAnimation {
    hkReferencedObject _base;
    AnimationType type;
    float duration;
    int numberOfTransformTracks;
    int numberOfFloatTracks;
    hkRefPtr_RE__hkaAnimatedReferenceFrame_41cd4124 extractedMotion;
    hkArray_RE__hkaAnnotationTrack_520f07a1 annotationTracks;
};
static_assert(sizeof(hkaAnimation) == 56, "hkaAnimation layout differs from the PDB");
