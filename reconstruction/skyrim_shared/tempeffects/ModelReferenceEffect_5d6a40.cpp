// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetAttached: Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:291
// ModelReferenceEffect::GetAttached: SIBLING(fo4-private@1b765c70, author-permission)
// flags: STANDIN GUESS(low)
// Get3D: Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:57
// ModelReferenceEffect, ModelReferenceEffect::Get3D: SIBLING(fo4-private@1b765c70, author-permission)
// 0x5d77c0 ModelReferenceEffect::GetAttached
// 0x5d6a40 ModelReferenceEffect::Get3D
#include "ModelReferenceEffect_5d6a40.h"

NiAVObject* ModelReferenceEffect::Get3D() const { return artObject; }

bool ModelReferenceEffect::GetAttached() const { return (flags & 1) != 0; }
