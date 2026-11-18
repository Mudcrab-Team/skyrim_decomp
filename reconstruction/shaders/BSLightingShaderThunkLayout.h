// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSLightingShader: EXE_RTTI
// BSLightingShaderThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ShaderBaseLayout.h"
namespace ResearchLayouts {
class BSLightingShaderThunkLayout : public ShaderBaseLayout {
public:
    BSLightingShaderThunkLayout();
    ~BSLightingShaderThunkLayout() override;
};
}
