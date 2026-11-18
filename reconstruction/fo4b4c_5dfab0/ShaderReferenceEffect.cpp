// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// ShaderReferenceEffect::Get3D: SIBLING(fo4-private@1b765c70, author-permission); adapted to target field accesses.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ShaderReferenceEffect.cpp:426
// names: GUESS(low); method name and signature are unverified.
// 0x5dfab0 ShaderReferenceEffect::Get3D
#include "ShaderReferenceEffect.h"
NiAVObject* ShaderReferenceEffect::Get3D() { return lastRootNode; }
