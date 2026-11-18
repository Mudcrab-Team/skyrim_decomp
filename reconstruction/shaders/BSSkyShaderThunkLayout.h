// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSSkyShader: EXE_RTTI
// BSSkyShaderThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ShaderBaseLayout.h"
namespace ResearchLayouts {
class BSSkyShaderThunkLayout : public ShaderBaseLayout {
public:
    BSSkyShaderThunkLayout();
    ~BSSkyShaderThunkLayout() override;
};
}
