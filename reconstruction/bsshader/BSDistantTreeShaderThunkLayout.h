// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSDistantTreeShader: EXE_RTTI
// BSDistantTreeShaderThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ShaderBaseLayout.h"
namespace ResearchLayouts {
class BSDistantTreeShaderThunkLayout : public ShaderBaseLayout {
public:
    BSDistantTreeShaderThunkLayout();
    ~BSDistantTreeShaderThunkLayout() override;
};
}
