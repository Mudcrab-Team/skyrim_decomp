// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh.json
// Adapted bodies: none
// 0x4a5600 PackageLocation::~PackageLocation
// CI hash: 0x4a5600 ??_GPackageLocation@@UEAAPEAXI@Z
#include "PackageLocation_4a5600.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
PackageLocation::PackageLocation()
{
}

// Reset location fields before restoring the base vftable.
// The CrashLogger name dtor_140443050 is a destructor entry of this class; it is written as the destructor.
PackageLocation::~PackageLocation()
{
    locType = -1;
    radius = 0;
    data = nullptr;
}
