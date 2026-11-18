// ActiveEffect, ShouldApply, GetEffect: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// 0x5bad70 ActiveEffect::ShouldApply

#include "ActiveEffect_5bad70.h"
bool ActiveEffect::ShouldApply(ActiveEffect** slot) { return *slot && (*slot)->GetEffect() != nullptr; }
