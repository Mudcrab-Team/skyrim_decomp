// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HandlerArray; size 0x48
#pragma once

#include "GArray_RE__GWaitable__HandlerStruct_2_RE__GArrayConstPolicy_0_16_true_026adb53.h"
#include "GLock.h"
#include "GNewOverrideBase_2_e860072d.h"
struct HandlerArray {
    GNewOverrideBase_2_e860072d _base;
    unsigned char undefined_1[7];
    GArray_RE__GWaitable__HandlerStruct_2_RE__GArrayConstPolicy_0_16_true_026adb53 handlers;
    GLock handlersLock;
};
static_assert(sizeof(HandlerArray) == 72, "HandlerArray layout differs from the PDB");
