// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderDistantBlur: EXE_RTTI
// BSImagespaceShaderDistantBlurThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderDistantBlurThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderDistantBlurThunkLayout();
    ~BSImagespaceShaderDistantBlurThunkLayout() override;
};
}
