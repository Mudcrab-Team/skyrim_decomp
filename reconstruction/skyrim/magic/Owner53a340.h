// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0x5da050 (skyrim/magic/PeakValueModifierEffect): source copied, names replaced by placeholders.
// Origin: target listing and anonymous sibling hints.
// MagicTarget, BGSLoadFormBuffer: GUESS(low)
// Function53a340, Owner53a340: GUESS(low) STANDIN
// ValueModifierEffect, FinishLoadGame, FindListPosition: GUESS(low) STANDIN
#pragma once
#include "PeakValueModifierEffect.h"

class Owner53a340 : public ValueModifierEffect {
public:
    void Function53a340(MagicTarget*);
    void FinishLoadGame(BGSLoadFormBuffer*);
    void FindListPosition();
};

