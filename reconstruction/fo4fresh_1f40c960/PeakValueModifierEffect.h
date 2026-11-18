// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// PeakValueModifierEffect, ActiveEffect, ValueModifierEffect, MagicTarget, BGSLoadFormBuffer, OnAdd, FinishLoadGame, FindListPosition: GUESS(low)
#pragma once
class MagicTarget;
class BGSLoadFormBuffer;
class ActiveEffect { public: void FinishLoadGame(BGSLoadFormBuffer*); };
class ValueModifierEffect : public ActiveEffect { public: void OnAdd(MagicTarget*); };
class PeakValueModifierEffect : public ValueModifierEffect {
public:
    void OnAdd(MagicTarget*);
    void FinishLoadGame(BGSLoadFormBuffer*);
    void FindListPosition();
};
