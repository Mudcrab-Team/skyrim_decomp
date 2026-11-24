// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// BGSPackageDataLocation::GetAsPackageLocation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageData.cpp:82
// BGSPackageDataLocation, BGSPackageDataLocation::GetAsPackageLocation: GUESS(low)
// BGSPackageDataLocation fields: STANDIN GUESS(low)
// 0x44df50 BGSPackageDataLocation::GetAsPackageLocation
// Code origin: Function44e0a0, Function44e0b0 and Function44df30 written for this reconstruction from the target listing; field offset measured there.
// Adapted bodies: GetAsPackageLocation from fo4-private@1b765c70; Function44e0a0, Function44e0b0, Function44df30 original.
// SPDX-License-Identifier: CC0-1.0
// 0x44e0a0 BGSPackageDataLocation::Function44e0a0
// 0x44e0b0 BGSPackageDataLocation::Function44e0b0
// 0x44df30 BGSPackageDataLocation::Function44df30
// Drafted by v-macrev, assisted by claude-sonnet-5-5 and claude-opus-5-5.
#include "BGSPackageDataLocation.h"
const PackageLocation* BGSPackageDataLocation::GetAsPackageLocation() const { return pointer ? pointer->GetAsPackageLocation() : nullptr; }

void BGSPackageDataLocation::Function44e0a0() { LocationDataA(data); }

void BGSPackageDataLocation::Function44e0b0() { LocationDataB(data); }

const WorldLocation* BGSPackageDataLocation::Function44df30(LocationContext* context) { return pointer ? pointer->AllocateLocation(context) : nullptr; }
