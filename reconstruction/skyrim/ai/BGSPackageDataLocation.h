// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Source exposure: mixed (pinned target listing and sibling hints).
// BGSPackageDataLocation, BGSPackageDataLocation::GetAsPackageLocation: GUESS(low)
// BGSPackageDataLocation fields: STANDIN GUESS(low)
// Supporting types: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot order from the pinned community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class PackageLocation; class LocationContext; class WorldLocation;
class LocationHandle { public: virtual ~LocationHandle() = default; virtual const WorldLocation* AllocateLocation(LocationContext*); virtual PackageLocation* GetAsPackageLocation(); };
class BGSPackageDataLocation {
public: const PackageLocation* GetAsPackageLocation() const;
private: std::uint8_t pad[0x18]; LocationHandle* pointer;
};
