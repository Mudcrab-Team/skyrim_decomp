// Source exposure: mixed (pinned image listing, public declarations and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// Compare: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataAmbush.cpp:40; adapted comparison.
// TESPackageData and virtual declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted declarations.
// TESAmbushPackageData: GUESS(low); qualified-name hint, target type name unverified.
// Pointer, referent and Compare semantics: GUESS(low); signatures unverified.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class TESForm; class BGSLoadFormBuffer;
class TESPackageData { public: virtual std::uint8_t Compare() const; virtual void Copy(TESPackageData*, TESForm*); virtual void InitItem(TESForm*); virtual void LoadGame(BGSLoadFormBuffer*); };
class Location { public: bool Compare(Location*); };
class TESAmbushPackageData : public TESPackageData { public: bool Compare(TESPackageData*); Location* ambushLocation; };
