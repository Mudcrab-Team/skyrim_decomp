// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// 0x1556600 BSEffectShaderMaterial::Function1556600
#include "BSEffectShaderMaterial.h"
void BSEffectShaderMaterial::Function1556600() { materialManager->ReleaseResource(sharedMaterial); sharedMaterial = nullptr; }
