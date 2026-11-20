// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbClipGenerator; size 0x110
#pragma once

#include "hkArray_RE__hkRefVariant_9938e2d5.h"
#include "hkQsTransform.h"
#include "hkRefPtr_RE__hkaDefaultAnimationControl_5f092a42.h"
#include "hkRefPtr_RE__hkbClipTriggerArray_91dbf6a1.h"
#include "hkRefVariant.h"
#include "hkStringPtr_33d8e88b.h"
#include "hkbGenerator.h"
struct hkaAnimationBinding;
struct hkaDefaultAnimationControlMapperData_ba8c0a01;
struct hkbClipGenerator {
    hkbGenerator _base;
    hkStringPtr_33d8e88b animationName;
    hkRefPtr_RE__hkbClipTriggerArray_91dbf6a1 triggers;
    float cropStartAmountLocalTime;
    float cropEndAmountLocalTime;
    float startTime;
    float playbackSpeed;
    float enforcedDuration;
    float userControlledTimeFraction;
    unsigned short animationBindingIndex;
    unsigned char mode_raw;
    unsigned char flags;
    unsigned int unk74;
    hkArray_RE__hkRefVariant_9938e2d5 animDatas;
    hkRefPtr_RE__hkaDefaultAnimationControl_5f092a42 animationControl;
    hkRefPtr_RE__hkbClipTriggerArray_91dbf6a1 originalTriggers;
    hkaDefaultAnimationControlMapperData_ba8c0a01* mapperData;
    hkaAnimationBinding* binding;
    hkRefVariant mirroredAnimation;
    hkQsTransform extractedMotion;
    hkArray_RE__hkRefVariant_9938e2d5 echos;
    float localTime;
    float time;
    float previousUserControlledTimeFraction;
    int bufferSize;
    int echoBufferSize;
    bool atEnd;
    bool ignoreStartTime;
    bool pingPongBackward;
    unsigned char pad107[9];
};
static_assert(sizeof(hkbClipGenerator) == 272, "hkbClipGenerator layout differs from the PDB");
