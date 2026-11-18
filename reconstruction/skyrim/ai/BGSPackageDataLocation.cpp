// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// BGSPackageDataLocation::GetAsPackageLocation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageData.cpp:82
// BGSPackageDataLocation, BGSPackageDataLocation::GetAsPackageLocation: GUESS(low)
// BGSPackageDataLocation fields: STANDIN GUESS(low)
// 0x44df50 BGSPackageDataLocation::GetAsPackageLocation
#include "BGSPackageDataLocation.h"
const PackageLocation* BGSPackageDataLocation::GetAsPackageLocation() const { return pointer ? pointer->GetAsPackageLocation() : nullptr; }
