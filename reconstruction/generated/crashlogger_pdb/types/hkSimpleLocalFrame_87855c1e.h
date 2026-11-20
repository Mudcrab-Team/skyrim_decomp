// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSimpleLocalFrame; size 0x80
// one of 2 different PDB types sharing this name
#pragma once

#include "hkArray_RE__hkRefPtr_RE__hkLocalFrame_1906cdb1.h"
#include "hkLocalFrame_02f726d8.h"
#include "hkRefPtr_RE__hkLocalFrame_5999ec6f.h"
#include "hkStringPtr_33d8e88b.h"
#include "hkTransform_d380b604.h"
struct hkLocalFrameGroup_1e8c3426;
struct hkSimpleLocalFrame_87855c1e {
    hkLocalFrame_02f726d8 _base;
    hkTransform_d380b604 transform;
    hkArray_RE__hkRefPtr_RE__hkLocalFrame_1906cdb1 children;
    hkLocalFrameGroup_1e8c3426* group;
    hkRefPtr_RE__hkLocalFrame_5999ec6f parentFrame;
    hkStringPtr_33d8e88b name;
    unsigned long long pad78;
};
static_assert(sizeof(hkSimpleLocalFrame_87855c1e) == 128, "hkSimpleLocalFrame_87855c1e layout differs from the PDB");
