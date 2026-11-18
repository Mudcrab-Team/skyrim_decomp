// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::UpdateCharacterControllerSimulationSettings: SIBLING(fo4-private@1b765c70, author-permission); adapted to target flag and global accesses.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:1415
// names: GUESS(low); global identity is inferred.
// 0x67d370 Actor::UpdateCharacterControllerSimulationSettings
#include "Actor.h"
void Actor::UpdateCharacterControllerSimulationSettings(bhkCharacterController& controller) { if (sceneIsComplex) controller.flags |= 0x100000; else controller.flags &= ~0x100000; }
