// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISVolumetricLightingBlurHCS: EXE_RTTI
// BSImagespaceShaderISVolumetricLightingBlurHCSThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISVolumetricLightingBlurHCSThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISVolumetricLightingBlurHCSThunkLayout();
    ~BSImagespaceShaderISVolumetricLightingBlurHCSThunkLayout() override;
};
}
