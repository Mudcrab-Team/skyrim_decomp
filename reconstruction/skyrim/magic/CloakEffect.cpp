// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CloakEffect::Update: SIBLING(fo4-private@1b765c70, author-permission); adapted to target tick width and helper call.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/CloakEffect.cpp:42
// names: GUESS(low); import and helper identities are inferred.
// 0x5c4170 CloakEffect::Update
#include "CloakEffect.h"
void CloakEffect::Update(float elapsed) { if ((unsigned)GetTickCount64() >= nextTargetCheck) FindTargets(elapsed); }
