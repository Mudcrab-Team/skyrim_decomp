// Source exposure: mixed (local target analysis and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// CombatTargetLocationSearchResult::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted object serialization.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatTargetMap.cpp:242
// CombatObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted base declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class BGSSaveGameBuffer;
class CombatObject {
public:
    virtual ~CombatObject();
    unsigned refCount;
};
class CombatTargetLocationSearch;
class CombatTargetLocation;
class CombatTargetLocationSearchResult : public CombatObject {
public:
    void SaveGame(BGSSaveGameBuffer* buffer) const;
    CombatTargetLocationSearch* search;
    CombatTargetLocation* location;
};
void SaveCombatObject(BGSSaveGameBuffer* buffer, const void* object);
