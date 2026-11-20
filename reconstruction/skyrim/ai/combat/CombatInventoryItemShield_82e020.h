// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// CombatInventoryItemShield::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:342
// CombatInventoryItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/C/CombatInventoryItem.h and include/RE/C/CombatObject.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class TESForm;
class BGSEquipSlot;
class CombatObject { public: virtual ~CombatObject(); unsigned refCount; };
struct CombatInventoryItemSlot { BGSEquipSlot* equipSlot; unsigned slot; };
class LoadBuffer { public: void LoadDataEndian(void*, unsigned, unsigned); };
class SaveBuffer { public: void SaveDataEndian(const void*, unsigned, unsigned, unsigned); };
class CombatInventoryItem : public CombatObject { public: TESForm* item; float itemScore; unsigned unknown; CombatInventoryItemSlot itemSlot; void LoadGame(LoadBuffer*); void SaveGame(SaveBuffer*); };
class CombatInventoryItemShield : public CombatInventoryItem { public: float maxRange; void SaveGame(SaveBuffer*); };
