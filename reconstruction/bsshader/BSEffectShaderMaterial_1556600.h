// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BSEffectShaderMaterial: STANDIN EXE_RTTI
// MaterialResource, MaterialResourceManager, materialManager, sharedMaterial, ReleaseResource, Function1556600: GUESS(low)
#pragma once
class MaterialResource;
class MaterialResourceManager { public: void ReleaseResource(MaterialResource*); };
extern MaterialResourceManager* materialManager;
extern MaterialResource* sharedMaterial;
class BSEffectShaderMaterial { public: static void Function1556600(); };
