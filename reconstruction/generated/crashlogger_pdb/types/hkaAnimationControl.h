// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaAnimationControl; size 0x58
#pragma once

#include "hkArray_RE__hkaAnimationControlListener_42e8dcfc.h"
#include "hkArray_unsigned_char_c72971e9.h"
#include "hkReferencedObject.h"
struct hkaAnimationBinding;
struct hkaAnimationControl {
    hkReferencedObject _base;
    float localTime;
    float weight;
    hkArray_unsigned_char_c72971e9 transformTrackWeights;
    hkArray_unsigned_char_c72971e9 floatTrackWeights;
    hkaAnimationBinding* binding;
    hkArray_RE__hkaAnimationControlListener_42e8dcfc listeners;
    float motionTrackWeight;
    unsigned int pad54;
};
static_assert(sizeof(hkaAnimationControl) == 88, "hkaAnimationControl layout differs from the PDB");
