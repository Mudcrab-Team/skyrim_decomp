// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbProjectStringData; size 0x78
#pragma once

#include "hkArray_RE__hkStringPtr_582be5ff.h"
#include "hkReferencedObject.h"
#include "hkStringPtr_33d8e88b.h"
struct hkbProjectStringData {
    hkReferencedObject _base;
    hkArray_RE__hkStringPtr_582be5ff animationFilenames;
    hkArray_RE__hkStringPtr_582be5ff behaviorFilenames;
    hkArray_RE__hkStringPtr_582be5ff characterFilenames;
    hkArray_RE__hkStringPtr_582be5ff eventNames;
    hkStringPtr_33d8e88b animationPath;
    hkStringPtr_33d8e88b behaviorPath;
    hkStringPtr_33d8e88b characterPath;
    hkStringPtr_33d8e88b scriptsPath;
    hkStringPtr_33d8e88b fullPathToSource;
};
static_assert(sizeof(hkbProjectStringData) == 120, "hkbProjectStringData layout differs from the PDB");
