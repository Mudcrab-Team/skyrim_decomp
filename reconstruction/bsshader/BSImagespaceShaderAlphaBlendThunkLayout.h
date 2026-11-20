// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderAlphaBlend: EXE_RTTI
// BSImagespaceShaderAlphaBlendThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderAlphaBlendThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderAlphaBlendThunkLayout();
    ~BSImagespaceShaderAlphaBlendThunkLayout() override;
};
}
