// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// CombatInventoryItemComposite::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:154
// CombatInventoryItem: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/C/CombatInventoryItem.h, include/RE/C/CombatObject.h and include/RE/N/NiRefObject.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class BGSSaveFormBuffer { public: void SaveFormID(void*, unsigned int); };
class NiRefObject { public: virtual ~NiRefObject(); unsigned int refCount; };
class CombatObject : public NiRefObject {};
class CombatInventoryItemSlot { public: void* equipSlot; unsigned int slot; };
class CombatInventoryItem : public CombatObject { public: void SaveGame(BGSSaveFormBuffer*) const; void* item; float itemScore; unsigned int unknown; CombatInventoryItemSlot itemSlot; };
class CombatInventoryItemComposite : public CombatInventoryItem { public: void SaveGame(BGSSaveFormBuffer*) const; void* secondaryItem; };
