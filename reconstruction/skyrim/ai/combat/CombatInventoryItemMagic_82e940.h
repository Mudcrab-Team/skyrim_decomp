// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/C/CombatInventoryItemMagic.h, CombatInventoryItem.h, CombatObject.h and RE/N/NiRefObject.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); setting identity and type are inferred from target.
#pragma once
class TESForm; class BGSEquipSlot;
class NiRefObject { public: virtual ~NiRefObject(); unsigned int refCount; };
class CombatObject : public NiRefObject {};
class CombatInventoryItem : public CombatObject { public: struct Slot { BGSEquipSlot* equipSlot; unsigned int slot; }; TESForm* item; float itemScore; unsigned int unknown; Slot itemSlot; };
extern float optimalRangePercent;
class CombatInventoryItemMagic : public CombatInventoryItem { public: float minRange, maxRange; float GetEquipRange(); float GetOptimalRange(); };
