// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderRadialBlur: EXE_RTTI
// BSImagespaceShaderRadialBlurThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderRadialBlurThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderRadialBlurThunkLayout();
    ~BSImagespaceShaderRadialBlurThunkLayout() override;
};
}
