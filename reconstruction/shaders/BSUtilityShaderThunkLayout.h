// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSUtilityShader: EXE_RTTI
// BSUtilityShaderThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ShaderBaseLayout.h"
namespace ResearchLayouts {
class BSUtilityShaderThunkLayout : public ShaderBaseLayout {
public:
    BSUtilityShaderThunkLayout();
    ~BSUtilityShaderThunkLayout() override;
};
}
