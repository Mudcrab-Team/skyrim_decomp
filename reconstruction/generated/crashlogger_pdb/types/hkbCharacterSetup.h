// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbCharacterSetup; size 0x68
#pragma once

#include "RE__hkArray_RE__hkRefPtr_RE__hkaSkeletonMapper_3a6a8091.h"
#include "RE__hkRefPtr_RE__hkaSkeletonMapper_c26b917a.h"
#include "RE__hkRefPtr_RE__hkaSkeleton_ed84e169.h"
#include "hkRefPtr_RE__hkaMirroredSkeleton_2998787d.h"
#include "hkRefPtr_RE__hkbAnimationBindingSet_3d6dcab9.h"
#include "hkRefPtr_RE__hkbCharacterData_b913511e.h"
#include "hkRefPtr_RE__hkbSymbolIdMap_ce816010.h"
#include "hkReferencedObject.h"
struct hkCriticalSection_342cc62e;
struct hkbCharacterSetup {
    hkReferencedObject _base;
    RE__hkArray_RE__hkRefPtr_RE__hkaSkeletonMapper_3a6a8091 retargetingSkeletonMappers;
    RE__hkRefPtr_RE__hkaSkeleton_ed84e169 animationSkeleton;
    RE__hkRefPtr_RE__hkaSkeletonMapper_c26b917a ragdollToAnimationSkeletonMapper;
    RE__hkRefPtr_RE__hkaSkeletonMapper_c26b917a animationToRagdollSkeletonMapper;
    hkRefPtr_RE__hkbAnimationBindingSet_3d6dcab9 animationBindingSet;
    hkRefPtr_RE__hkbCharacterData_b913511e data;
    RE__hkRefPtr_RE__hkaSkeleton_ed84e169 unscaledAnimationSkeleton;
    hkRefPtr_RE__hkaMirroredSkeleton_2998787d mirroredSkeleton;
    hkRefPtr_RE__hkbSymbolIdMap_ce816010 characterPropertyIdMap;
    hkCriticalSection_342cc62e* criticalSection;
};
static_assert(sizeof(hkbCharacterSetup) == 104, "hkbCharacterSetup layout differs from the PDB");
