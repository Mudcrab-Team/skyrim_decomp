// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiPointer::~NiPointer as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfcda50 BSMultiBound::~BSMultiBound
#include "BSMultiBound_fcda50.h"

// Emit the class vftable and scalar deleting destructor.
BSMultiBound::BSMultiBound() = default;

// Release the bound shape reference on destruction.
BSMultiBound::~BSMultiBound()
{
    data = nullptr;
}
