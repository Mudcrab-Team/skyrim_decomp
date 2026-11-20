// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaAnnotationTrack; size 0x18
#pragma once

#include "hkArray_RE__hkaAnnotationTrack__Annotation_62b14470.h"
#include "hkStringPtr_33d8e88b.h"
struct hkaAnnotationTrack {
    hkStringPtr_33d8e88b trackName;
    hkArray_RE__hkaAnnotationTrack__Annotation_62b14470 annotations;
};
static_assert(sizeof(hkaAnnotationTrack) == 24, "hkaAnnotationTrack layout differs from the PDB");
