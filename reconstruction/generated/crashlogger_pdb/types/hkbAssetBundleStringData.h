// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbAssetBundleStringData; size 0x18
#pragma once

#include "hkArray_RE__hkStringPtr_582be5ff.h"
#include "hkStringPtr_33d8e88b.h"
struct hkbAssetBundleStringData {
    hkStringPtr_33d8e88b bundleName;
    hkArray_RE__hkStringPtr_582be5ff assetNames;
};
static_assert(sizeof(hkbAssetBundleStringData) == 24, "hkbAssetBundleStringData layout differs from the PDB");
