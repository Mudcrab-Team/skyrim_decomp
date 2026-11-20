// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatMagicCasterWard, CombatMagicCaster, CombatObject, NiRefObject, AITimer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LoadGame, cooldownTimer, aiTimer, timer, inventoryItem, magicItem, _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AITimer::Load: GUESS(low)
#pragma once
#include <cstdint>
class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class CombatInventoryItemMagic;
class MagicItem;
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); std::uint32_t _refCount; std::uint32_t _pad0C; };
class CombatObject : public NiRefObject { public: virtual std::uint32_t GetObjectType(); virtual void SaveGame(BGSSaveGameBuffer*); virtual void LoadGame(BGSLoadGameBuffer*); };
class CombatMagicCaster : public CombatObject { public: void LoadGame(BGSLoadGameBuffer*) override; CombatInventoryItemMagic* inventoryItem; MagicItem* magicItem; };
struct AITimer { void Load(BGSLoadGameBuffer*); float aiTimer; float timer; };
class CombatMagicCasterWard : public CombatMagicCaster { public: void LoadGame(BGSLoadGameBuffer*) override; AITimer cooldownTimer; };
