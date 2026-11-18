// Source exposure: mixed (pinned image listing, public declarations and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// Copy: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataPatrol.cpp:42; adapted cast and copy.
// Compare: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataPatrol.cpp:54; adapted cast and comparison.
// LoadGame: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataPatrol.cpp:89; adapted two loads.
// TESPackageData and virtual declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted declarations.
// TESPatrolPackageData: GUESS(low); qualified-name hint, target type name unverified.
// Field names and semantics: GUESS(low); from target accesses and sibling, signatures unverified.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class TESForm;
class BGSLoadFormBuffer { public: void LoadDataEndian(void*, unsigned int, unsigned int); };
class TESPackageData { public: virtual std::uint8_t Compare() const; virtual void Copy(TESPackageData*, TESForm*); virtual void InitItem(TESForm*); virtual void LoadGame(BGSLoadFormBuffer*); };
class TESPatrolPackageData : public TESPackageData { public: void Copy(TESPackageData*, TESForm*) override; bool Compare(TESPackageData*); void LoadGame(BGSLoadFormBuffer*) override; bool repeatable; bool startAtNearestPoint; };
