// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Source exposure: mixed (pinned target listing and sibling hints).
// Code origin: the member at 0x10 and Function44e0a0, Function44e0b0, Function44df30 written for this reconstruction from the target listing.
// BGSPackageDataLocation, BGSPackageDataLocation::GetAsPackageLocation: GUESS(low)
// BGSPackageDataLocation fields: STANDIN GUESS(low)
// LocationDataA, LocationDataB: GUESS(low); invented names for the two called functions
// Supporting types: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot order from the pinned community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class PackageLocation; class LocationContext; class WorldLocation;
class LocationHandle { public: virtual ~LocationHandle() = default; virtual const WorldLocation* AllocateLocation(LocationContext*); virtual PackageLocation* GetAsPackageLocation(); };
void LocationDataA(void* data);
void LocationDataB(void* data);
class BGSPackageDataLocation {
public: const PackageLocation* GetAsPackageLocation() const;
private: std::uint8_t pad[0x10]; void* data; LocationHandle* pointer;
public:
    void Function44e0a0();
    void Function44e0b0();
    const WorldLocation* Function44df30(LocationContext* context);
};
