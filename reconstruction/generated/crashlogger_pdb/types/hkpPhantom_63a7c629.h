// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpPhantom; size 0xf0
// one of 2 different PDB types sharing this name
#pragma once

#include "hkArray_RE__hkpPhantomListener_3d5082c5.h"
#include "hkArray_RE__hkpPhantomOverlapListener_65711243.h"
#include "hkpWorldObject_690af56a.h"
struct hkpPhantom_63a7c629 {
    hkpWorldObject_690af56a _base;
    hkArray_RE__hkpPhantomOverlapListener_65711243 overlapListeners;
    hkArray_RE__hkpPhantomListener_3d5082c5 phantomListeners;
};
static_assert(sizeof(hkpPhantom_63a7c629) == 240, "hkpPhantom_63a7c629 layout differs from the PDB");
