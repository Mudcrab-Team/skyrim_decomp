// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// EffectSetting::GetEffectShader: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EffectSetting.cpp:299
// names: GUESS(low); call identities and method names remain unverified.
// 0x14b700 EffectSetting::GetEffectShader
#include "EffectSetting_14b700.h"
TESEffectShader* EffectSetting::GetEffectShader(bool dual) { auto visual = data.hitVisuals; auto result = visual ? visual->data.effectShader : data.effectShader; if (dual && data.dualCastData && data.dualCastData->data.effectShader) result = data.dualCastData->data.effectShader; return result; }
