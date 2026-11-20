// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISCompositeLensFlareVolumetricLighting: EXE_RTTI
// BSImagespaceShaderISCompositeLensFlareVolumetricLightingThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISCompositeLensFlareVolumetricLightingThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISCompositeLensFlareVolumetricLightingThunkLayout();
    ~BSImagespaceShaderISCompositeLensFlareVolumetricLightingThunkLayout() override;
};
}
