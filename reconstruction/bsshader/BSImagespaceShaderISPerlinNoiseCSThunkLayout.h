// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISPerlinNoiseCS: EXE_RTTI
// BSImagespaceShaderISPerlinNoiseCSThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISPerlinNoiseCSThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISPerlinNoiseCSThunkLayout();
    ~BSImagespaceShaderISPerlinNoiseCSThunkLayout() override;
};
}
