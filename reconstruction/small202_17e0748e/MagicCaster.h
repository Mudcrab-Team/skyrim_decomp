// Origin: declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT); body original.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// MagicCaster, State, StartChargeImpl, StartReadyImpl, sounds, desiredTarget, currentSpell, state, castingTimer, currentSpellCost, magnitudeOverride, nextTargetUpdate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSTArray, BSSoundHandle, ObjectRefHandle, MagicItem, TESObjectREFR, Actor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ChangeState, UpdateNextTargetTime, GetTimeOffset: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class BSSoundHandle;
class MagicItem;
class TESObjectREFR;
class Actor;
template<class T> struct BSTArray {
 T* data; std::uint32_t capacity; std::uint32_t pad0c;
 std::uint32_t size; std::uint32_t pad14;
};
struct ObjectRefHandle { std::uint32_t nativeHandle; };
class MagicCaster {
public:
 enum class State : std::uint32_t { kUnk02 = 2, kReady = 3 };
 virtual ~MagicCaster();
 virtual void CastSpellImmediate(MagicItem*, bool, TESObjectREFR*, float, bool, float, Actor*);
 virtual void FindTouchTarget();
 virtual void RequestCastImpl();
 virtual bool StartChargeImpl();
 virtual void StartReadyImpl();
 void ChangeState(State);
 void UpdateNextTargetTime();
 float GetTimeOffset() const;
 BSTArray<BSSoundHandle> sounds;
 ObjectRefHandle desiredTarget;
 std::uint32_t pad24;
 MagicItem* currentSpell;
 State state;
 float castingTimer;
 float currentSpellCost;
 float magnitudeOverride;
 float nextTargetUpdate;
};
