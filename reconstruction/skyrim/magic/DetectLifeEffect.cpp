// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// DetectLifeEffect::CheckCustomSkillUseConditions: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call and comparison.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DetectLifeEffect.cpp:12
// names: GUESS(low); global identity is inferred.
// 0x5c58a0 DetectLifeEffect::CheckCustomSkillUseConditions
#include "DetectLifeEffect.h"
bool DetectLifeEffect::CheckCustomSkillUseConditions() const { return target->GetTargetAsActor() != player; }
