// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISParallaxMaskBlurHCS: EXE_RTTI
// BSImagespaceShaderISParallaxMaskBlurHCSThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISParallaxMaskBlurHCSThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISParallaxMaskBlurHCSThunkLayout();
    ~BSImagespaceShaderISParallaxMaskBlurHCSThunkLayout() override;
};
}
