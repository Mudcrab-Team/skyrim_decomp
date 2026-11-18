// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISLightingCompositeNoDirectionalLight: EXE_RTTI
// BSImagespaceShaderISLightingCompositeNoDirectionalLightThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISLightingCompositeNoDirectionalLightThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISLightingCompositeNoDirectionalLightThunkLayout();
    ~BSImagespaceShaderISLightingCompositeNoDirectionalLightThunkLayout() override;
};
}
