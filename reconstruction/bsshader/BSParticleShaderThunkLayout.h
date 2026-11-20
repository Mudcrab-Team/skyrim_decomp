// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSParticleShader: EXE_RTTI
// BSParticleShaderThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ShaderBaseLayout.h"
namespace ResearchLayouts {
class BSParticleShaderThunkLayout : public ShaderBaseLayout {
public:
    BSParticleShaderThunkLayout();
    ~BSParticleShaderThunkLayout() override;
};
}
