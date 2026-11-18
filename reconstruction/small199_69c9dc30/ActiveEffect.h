// ActiveEffect, ShouldApply, GetEffect: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).

#pragma once
// ActiveEffect, ShouldApply, GetEffect: GUESS(low)
class ActiveEffect {
public:
    void* GetEffect();
    static bool ShouldApply(ActiveEffect**);
};
