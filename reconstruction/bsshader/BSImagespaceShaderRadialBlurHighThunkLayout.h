// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderRadialBlurHigh: EXE_RTTI
// BSImagespaceShaderRadialBlurHighThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderRadialBlurHighThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderRadialBlurHighThunkLayout();
    ~BSImagespaceShaderRadialBlurHighThunkLayout() override;
};
}
