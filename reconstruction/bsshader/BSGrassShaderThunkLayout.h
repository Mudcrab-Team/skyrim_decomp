// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSGrassShader: EXE_RTTI
// BSGrassShaderThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ShaderBaseLayout.h"
namespace ResearchLayouts {
class BSGrassShaderThunkLayout : public ShaderBaseLayout {
public:
    BSGrassShaderThunkLayout();
    ~BSGrassShaderThunkLayout() override;
};
}
