// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// VM, Actor, TESIdleForm, TESObjectREFR, KillImpl, PlayIdleImpl: GUESS(low)
// papyrus::Actor: STANDIN GUESS(low); organizational grouping for static wrappers, with no instances or represented layout
// KillSilent, Kill, PlayIdle, PlayIdleWithTarget: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once
#include <cstdint>
class VM;
class Actor;
class TESIdleForm;
class TESObjectREFR;
namespace papyrus { class Actor { public:
static void KillSilent(VM*, std::uint32_t, ::Actor*, ::Actor*);
static void Kill(VM*, std::uint32_t, ::Actor*, ::Actor*);
static bool PlayIdle(VM*, std::uint32_t, ::Actor*, TESIdleForm*);
static bool PlayIdleWithTarget(VM*, std::uint32_t, ::Actor*, TESIdleForm*, TESObjectREFR*);
}; }
void KillImpl(::Actor*, ::Actor*, bool, VM*, std::uint32_t);
bool PlayIdleImpl(::Actor*, TESIdleForm*, TESObjectREFR*, VM*, std::uint32_t);
