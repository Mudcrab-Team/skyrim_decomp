// Source exposure: mixed (pinned image listing, public declarations and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0x4a0b50 (skyrim/ai/TESEscortPackageData): source copied, names replaced by placeholders.
// Origin: original reconstruction using target listing and anonymous sibling hints.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataEscort.cpp:52
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataEscort.cpp:76
// Location, Location::Compare, BGSSaveFormBuffer: GUESS(low); inferred from target accesses and sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function4a0ed0, Owner4a0ed0: GUESS(low) STANDIN
// TESPackageData: GUESS(low) STANDIN
#pragma once
#include "TESEscortPackageData.h"

class Owner4a0ed0 : public TESPackageData { public: bool Compare(TESPackageData*); void Function4a0ed0(BGSSaveFormBuffer*); Location* searchLocation; unsigned int followRadius; };
