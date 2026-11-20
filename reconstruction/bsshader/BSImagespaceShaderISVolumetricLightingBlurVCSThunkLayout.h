// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISVolumetricLightingBlurVCS: EXE_RTTI
// BSImagespaceShaderISVolumetricLightingBlurVCSThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISVolumetricLightingBlurVCSThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISVolumetricLightingBlurVCSThunkLayout();
    ~BSImagespaceShaderISVolumetricLightingBlurVCSThunkLayout() override;
};
}
