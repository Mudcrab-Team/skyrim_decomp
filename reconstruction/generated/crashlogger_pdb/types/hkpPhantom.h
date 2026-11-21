// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpPhantom; size 0xf0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_RE__hkpPhantomListener_3d5082c5.h"
#include "hkArray_RE__hkpPhantomOverlapListener_65711243.h"
#include "hkpWorldObject.h"
struct hkpPhantom {
    hkpWorldObject _base;
    hkArray_RE__hkpPhantomOverlapListener_65711243 overlapListeners;
    hkArray_RE__hkpPhantomListener_3d5082c5 phantomListeners;
};
static_assert(sizeof(hkpPhantom) == 240, "hkpPhantom layout differs from the PDB");
