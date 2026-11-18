// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSBloodSplatterShader: EXE_RTTI
// BSBloodSplatterShaderThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ShaderBaseLayout.h"
namespace ResearchLayouts {
class BSBloodSplatterShaderThunkLayout : public ShaderBaseLayout {
public:
    BSBloodSplatterShaderThunkLayout();
    ~BSBloodSplatterShaderThunkLayout() override;
};
}
