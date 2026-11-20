// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSEffectShader: EXE_RTTI
// BSEffectShaderThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ShaderBaseLayout.h"
namespace ResearchLayouts {
class BSEffectShaderThunkLayout : public ShaderBaseLayout {
public:
    BSEffectShaderThunkLayout();
    ~BSEffectShaderThunkLayout() override;
};
}
