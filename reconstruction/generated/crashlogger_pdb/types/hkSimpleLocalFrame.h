// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSimpleLocalFrame; size 0x80
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_RE__hkRefPtr_RE__hkLocalFrame_1906cdb1.h"
#include "hkLocalFrame.h"
#include "hkRefPtr_RE__hkLocalFrame_5999ec6f.h"
#include "hkStringPtr.h"
#include "hkTransform.h"
struct hkLocalFrameGroup;
struct hkSimpleLocalFrame {
    hkLocalFrame _base;
    hkTransform transform;
    hkArray_RE__hkRefPtr_RE__hkLocalFrame_1906cdb1 children;
    hkLocalFrameGroup* group;
    hkRefPtr_RE__hkLocalFrame_5999ec6f parentFrame;
    hkStringPtr name;
    unsigned long long pad78;
};
static_assert(sizeof(hkSimpleLocalFrame) == 128, "hkSimpleLocalFrame layout differs from the PDB");
