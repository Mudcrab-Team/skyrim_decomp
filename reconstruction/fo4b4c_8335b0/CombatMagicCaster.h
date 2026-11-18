// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/C/CombatMagicCaster.h, CombatObject.h and RE/N/NiRefObject.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); save helper and field type inferred from target.
#pragma once
class BGSSaveGameBuffer; class CombatInventoryItemMagic;
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount; };
class CombatObject : public NiRefObject { public: void SaveGame(BGSSaveGameBuffer*) const; };
void SaveCombatObject(BGSSaveGameBuffer*, CombatInventoryItemMagic*);
class CombatMagicCaster : public CombatObject { public: CombatInventoryItemMagic* inventoryItem; void SaveGame(BGSSaveGameBuffer*) const; };
