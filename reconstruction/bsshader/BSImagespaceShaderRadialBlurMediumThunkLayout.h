// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderRadialBlurMedium: EXE_RTTI
// BSImagespaceShaderRadialBlurMediumThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderRadialBlurMediumThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderRadialBlurMediumThunkLayout();
    ~BSImagespaceShaderRadialBlurMediumThunkLayout() override;
};
}
