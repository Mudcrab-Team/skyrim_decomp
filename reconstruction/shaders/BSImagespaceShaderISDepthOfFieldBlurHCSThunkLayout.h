// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISDepthOfFieldBlurHCS: EXE_RTTI
// BSImagespaceShaderISDepthOfFieldBlurHCSThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISDepthOfFieldBlurHCSThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISDepthOfFieldBlurHCSThunkLayout();
    ~BSImagespaceShaderISDepthOfFieldBlurHCSThunkLayout() override;
};
}
