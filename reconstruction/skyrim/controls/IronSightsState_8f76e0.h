// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// IronSightsState, Begin, PlayerCharacter, Show1stPerson, player: GUESS(low)
#pragma once
class PlayerCharacter { public: void Show1stPerson(bool); };
extern PlayerCharacter* player;
class IronSightsState { public: void Begin(); };
