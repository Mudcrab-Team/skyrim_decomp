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
// 0x4a0ac0 TESEscortPackageData::Compare
// 0x4a0b50 TESEscortPackageData::SaveGame
#include "TESEscortPackageData.h"
bool TESEscortPackageData::Compare(TESPackageData* src) { auto* p = dynamic_cast<TESEscortPackageData*>(src); if (!p) return true; if (searchLocation) { if (searchLocation->Compare(p->searchLocation)) return true; } else if (p->searchLocation) return true; if (followRadius != p->followRadius) return true; return false; }
void TESEscortPackageData::SaveGame(BGSSaveFormBuffer* b) { b->SaveData(&followRadius, 4, 4, false); bool hasLocation = searchLocation != nullptr; b->SaveData(&hasLocation, 1, 1, false); if (hasLocation) searchLocation->SaveGame(b); }
