// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbCharacterStringData; size 0xc0
#pragma once

#include "hkArray_RE__hkStringPtr_582be5ff.h"
#include "hkArray_RE__hkbAssetBundleStringData_f4668f40.h"
#include "hkArray_RE__hkbCharacterStringData__FileNameMeshNamePair_1f2bcb27.h"
#include "hkReferencedObject.h"
#include "hkStringPtr_33d8e88b.h"
struct hkbCharacterStringData {
    hkReferencedObject _base;
    hkArray_RE__hkbCharacterStringData__FileNameMeshNamePair_1f2bcb27 deformableSkinNames;
    hkArray_RE__hkbCharacterStringData__FileNameMeshNamePair_1f2bcb27 rigidSkinNames;
    hkArray_RE__hkStringPtr_582be5ff animationNames;
    hkArray_RE__hkbAssetBundleStringData_f4668f40 animationBundleFilenameData;
    hkArray_RE__hkStringPtr_582be5ff characterPropertyNames;
    hkArray_RE__hkStringPtr_582be5ff retargetingSkeletonMapperFilenames;
    hkArray_RE__hkStringPtr_582be5ff lodNames;
    hkArray_RE__hkStringPtr_582be5ff mirroredSyncPointSubstringsA;
    hkArray_RE__hkStringPtr_582be5ff mirroredSyncPointSubstringsB;
    hkStringPtr_33d8e88b name;
    hkStringPtr_33d8e88b rigName;
    hkStringPtr_33d8e88b ragdollName;
    hkStringPtr_33d8e88b behaviorFilename;
};
static_assert(sizeof(hkbCharacterStringData) == 192, "hkbCharacterStringData layout differs from the PDB");
