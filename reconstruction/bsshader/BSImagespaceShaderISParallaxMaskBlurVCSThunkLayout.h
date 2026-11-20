// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISParallaxMaskBlurVCS: EXE_RTTI
// BSImagespaceShaderISParallaxMaskBlurVCSThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISParallaxMaskBlurVCSThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISParallaxMaskBlurVCSThunkLayout();
    ~BSImagespaceShaderISParallaxMaskBlurVCSThunkLayout() override;
};
}
