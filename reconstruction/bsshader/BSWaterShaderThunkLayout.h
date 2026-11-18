// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSWaterShader: EXE_RTTI
// BSWaterShaderThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ShaderBaseLayout.h"
namespace ResearchLayouts {
class BSWaterShaderThunkLayout : public ShaderBaseLayout {
public:
    BSWaterShaderThunkLayout();
    ~BSWaterShaderThunkLayout() override;
};
}
