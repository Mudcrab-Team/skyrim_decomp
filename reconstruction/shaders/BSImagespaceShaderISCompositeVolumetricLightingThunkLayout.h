// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISCompositeVolumetricLighting: EXE_RTTI
// BSImagespaceShaderISCompositeVolumetricLightingThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISCompositeVolumetricLightingThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISCompositeVolumetricLightingThunkLayout();
    ~BSImagespaceShaderISCompositeVolumetricLightingThunkLayout() override;
};
}
