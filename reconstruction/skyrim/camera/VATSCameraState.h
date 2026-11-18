// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/VATSCameraState.cpp:36 (VATSCameraState::Begin)
// VATSCameraState, Begin: GUESS(low)
#pragma once
// PlayerCharacter, player, Show1stPerson: GUESS(low)
class PlayerCharacter { public: void Show1stPerson(bool); };
extern PlayerCharacter* player;
class VATSCameraState { public: void Begin(); };
