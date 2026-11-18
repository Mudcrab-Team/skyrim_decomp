// Source exposure: mixed (pinned image listing, public declarations and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// Copy: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataPatrol.cpp:42; adapted cast and copy.
// Compare: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataPatrol.cpp:54; adapted cast and comparison.
// LoadGame: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataPatrol.cpp:89; adapted two loads.
// TESPackageData and virtual declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted declarations.
// TESPatrolPackageData: GUESS(low); qualified-name hint, target type name unverified.
// Field names and semantics: GUESS(low); from target accesses and sibling, signatures unverified.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4a10d0 TESPatrolPackageData::Copy
// 0x4a1120 TESPatrolPackageData::Compare
// 0x4a11f0 TESPatrolPackageData::LoadGame
#include "TESPatrolPackageData.h"
void TESPatrolPackageData::Copy(TESPackageData* src, TESForm*) { if (auto* p = dynamic_cast<TESPatrolPackageData*>(src)) { repeatable = p->repeatable; startAtNearestPoint = p->startAtNearestPoint; } }
bool TESPatrolPackageData::Compare(TESPackageData* src) { auto* p = dynamic_cast<TESPatrolPackageData*>(src); return !p || repeatable != p->repeatable || startAtNearestPoint != p->startAtNearestPoint; }
void TESPatrolPackageData::LoadGame(BGSLoadFormBuffer* b) { b->LoadDataEndian(&repeatable, 1, 1); b->LoadDataEndian(&startAtNearestPoint, 1, 1); }
