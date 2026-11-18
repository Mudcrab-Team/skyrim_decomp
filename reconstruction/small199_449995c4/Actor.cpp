// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// 0xa012c0 papyrus::Actor::KillSilent
// 0xa012f0 papyrus::Actor::Kill
// 0xa01930 papyrus::Actor::PlayIdle
// 0xa01960 papyrus::Actor::PlayIdleWithTarget
#include "Actor.h"
namespace papyrus {
void Actor::KillSilent(VM* vm, std::uint32_t stack, ::Actor* self, ::Actor* killer) { KillImpl(self, killer, false, vm, stack); }
void Actor::Kill(VM* vm, std::uint32_t stack, ::Actor* self, ::Actor* killer) { KillImpl(self, killer, true, vm, stack); }
bool Actor::PlayIdle(VM* vm, std::uint32_t stack, ::Actor* self, TESIdleForm* idle) { return PlayIdleImpl(self, idle, nullptr, vm, stack); }
bool Actor::PlayIdleWithTarget(VM* vm, std::uint32_t stack, ::Actor* self, TESIdleForm* idle, TESObjectREFR* target) { return PlayIdleImpl(self, idle, target, vm, stack); }
}
