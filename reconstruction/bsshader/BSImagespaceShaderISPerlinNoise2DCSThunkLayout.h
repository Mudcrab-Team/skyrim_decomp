// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISPerlinNoise2DCS: EXE_RTTI
// BSImagespaceShaderISPerlinNoise2DCSThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISPerlinNoise2DCSThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISPerlinNoise2DCSThunkLayout();
    ~BSImagespaceShaderISPerlinNoise2DCSThunkLayout() override;
};
}
