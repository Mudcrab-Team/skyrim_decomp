// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// LightEffect, ActiveEffect, BGSLoadFormBuffer, Revert, DetachLight: GUESS(low)
#pragma once
class BGSLoadFormBuffer;
class ActiveEffect { public: void Revert(BGSLoadFormBuffer*); };
class LightEffect : public ActiveEffect { public: void Revert(BGSLoadFormBuffer*); void DetachLight(); };
