// Source exposure: mixed (pinned image listing, public declarations and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// TESEscortPackageData::Compare: SIBLING(fo4-private@1b765c70, author-permission); adapted comparison.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataEscort.cpp:52
// TESEscortPackageData::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted save sequence.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataEscort.cpp:76
// TESPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) GUESS(low); adapted declaration, target type identity unverified.
// TESEscortPackageData: GUESS(low); qualified-name hint, target type identity unverified.
// TESEscortPackageData::searchLocation, TESEscortPackageData::followRadius, Location, Location::Compare, Location::SaveGame, BGSSaveFormBuffer, BGSSaveFormBuffer::SaveData: GUESS(low); inferred from target accesses and sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class TESForm; class BGSLoadFormBuffer;
class BGSSaveFormBuffer { public: void SaveData(const void*, unsigned int, unsigned int, unsigned int); };
class TESPackageData { public: virtual std::uint8_t Compare() const; virtual void Copy(TESPackageData*, TESForm*); virtual void InitItem(TESForm*); virtual void LoadGame(BGSLoadFormBuffer*); };
class Location { public: bool Compare(Location*); void SaveGame(BGSSaveFormBuffer*); };
class TESEscortPackageData : public TESPackageData { public: bool Compare(TESPackageData*); void SaveGame(BGSSaveFormBuffer*); Location* searchLocation; unsigned int followRadius; };
