// Source exposure: mixed (local target analysis and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// CombatTargetLocationSearchResult::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted object serialization.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatTargetMap.cpp:242
// CombatObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted base declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x85a990 CombatTargetLocationSearchResult::SaveGame
#include "CombatTargetLocationSearchResult.h"
void CombatTargetLocationSearchResult::SaveGame(BGSSaveGameBuffer* buffer) const {
    SaveCombatObject(buffer, search);
    SaveCombatObject(buffer, location);
}
