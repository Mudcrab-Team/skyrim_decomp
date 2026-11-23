// Code origin: original declarations inferred from the pinned listing, with names as labelled below
// Source exposure: binary-analysis
// BSIsActiveModifier: EXE_RTTI
// UpdateFlagsInverted, Pair, active, disabled, pairs, pad, Refresh: GUESS(low)
#pragma once
class BSIsActiveModifier {
public:
    void UpdateFlagsInverted();
    struct Pair { bool active; unsigned char disabled; void Refresh() { active = !disabled; } };
    char pad[0x50];
    Pair pairs[5];
};
