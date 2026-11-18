// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// ShaderReferenceEffect::Push: SIBLING(fo4-private@1b765c70, author-permission); adapted to target field accesses.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ShaderReferenceEffect.cpp:393
// names: GUESS(low); method name and signature are unverified.
// 0x5dfdb0 ShaderReferenceEffect::Push
#include "ShaderReferenceEffect.h"
void ShaderReferenceEffect::Push() { if (effectShaderData) ++pushCount; }
