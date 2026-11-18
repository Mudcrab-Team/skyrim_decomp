// Source exposure: mixed
// Origin: authorized sibling and community declarations
// MagicCaster::FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/MagicCaster.cpp:379
// MagicCaster, MagicCaster::PrepareSound, MagicCaster::currentSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/M/MagicCaster.h
// names: GUESS(low); signature and local iteration are provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class MagicItem; class Actor; class ActiveEffect; class TESObjectREFR; class NiNode; class BGSSaveGameBuffer; class BGSLoadGameBuffer;
namespace MagicSystem { enum class SoundID : int {}; enum class CannotCastReason : int {}; enum class CastingSource : int {}; }
struct BSSoundHandle { std::uint32_t soundID; bool assumeSuccess; std::uint32_t state; };
template<class T> struct BSTArray { T* data; std::uint32_t capacity; std::uint32_t pad; std::uint32_t size; std::uint32_t pad2; };
class MagicCaster {
public:
 virtual ~MagicCaster();
 virtual void CastSpellImmediate(MagicItem*, bool, TESObjectREFR*, float, bool, float, Actor*);
 virtual void FindTouchTarget();
 virtual void RequestCastImpl();
 virtual bool StartChargeImpl();
 virtual bool StartReadyImpl();
 virtual void StartCastImpl();
 virtual void FinishCastImpl();
 virtual void InterruptCastImpl(bool);
 virtual void SpellCast(bool, std::uint32_t, MagicItem*);
 virtual bool CheckCast(MagicItem*, bool, float*, MagicSystem::CannotCastReason*, bool);
 virtual TESObjectREFR* GetCasterStatsObject() const;
 virtual Actor* GetCasterAsActor() const;
 virtual TESObjectREFR* GetCasterObjectReference(Actor**) const;
 virtual NiNode* GetMagicNode();
 virtual void ClearMagicNode();
 virtual void SetCurrentSpellImpl(MagicItem*);
 virtual void SelectSpellImpl();
 virtual void DeselectSpellImpl();
 virtual void SetSkipCheckCast();
 virtual void SetCastingTimerForCharge();
 virtual MagicSystem::CastingSource GetCastingSource() const;
 virtual bool GetIsDualCasting() const;
 virtual void SetDualCasting(bool);
 virtual void SaveGame(BGSSaveGameBuffer*);
 virtual void LoadGame(BGSLoadGameBuffer*);
 virtual void FinishLoadGame(BGSLoadGameBuffer*);
 virtual void PrepareSound(MagicSystem::SoundID, MagicItem*);
 virtual void AdjustActiveEffect(ActiveEffect*, float, bool);
 BSTArray<BSSoundHandle> sounds;
 std::uint32_t desiredTarget;
 std::uint32_t pad24;
 MagicItem* currentSpell;
};
