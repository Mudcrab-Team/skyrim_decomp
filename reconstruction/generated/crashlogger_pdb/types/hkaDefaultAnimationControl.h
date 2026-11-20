// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaDefaultAnimationControl; size 0xc0
#pragma once

#include "EaseStatus.h"
#include "hkArray_RE__hkaDefaultAnimationControlListener_0d8beee7.h"
#include "hkVector4.h"
#include "hkaAnimationControl.h"
struct hkaDefaultAnimationControlMapperData_ba8c0a01;
struct hkaDefaultAnimationControl {
    hkaAnimationControl _base;
    float masterWeight;
    float playbackSpeed;
    unsigned int overflowCount;
    unsigned int underflowCount;
    int maxCycles;
    unsigned int pad6C;
    hkVector4 easeInCurve;
    hkVector4 easeOutCurve;
    float easeInvDuration;
    float easeT;
    EaseStatus easeStatus;
    float cropStartAmountLocalTime;
    float cropEndAmountLocalTime;
    unsigned int padA4;
    hkArray_RE__hkaDefaultAnimationControlListener_0d8beee7 defaultListeners;
    hkaDefaultAnimationControlMapperData_ba8c0a01* mapper;
};
static_assert(sizeof(hkaDefaultAnimationControl) == 192, "hkaDefaultAnimationControl layout differs from the PDB");
