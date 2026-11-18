// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISLightingCompositeMenu: EXE_RTTI
// BSImagespaceShaderISLightingCompositeMenuThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISLightingCompositeMenuThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISLightingCompositeMenuThunkLayout();
    ~BSImagespaceShaderISLightingCompositeMenuThunkLayout() override;
};
}
