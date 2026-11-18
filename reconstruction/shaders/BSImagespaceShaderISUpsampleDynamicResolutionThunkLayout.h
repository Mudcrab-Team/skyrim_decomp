// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISUpsampleDynamicResolution: EXE_RTTI
// BSImagespaceShaderISUpsampleDynamicResolutionThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISUpsampleDynamicResolutionThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISUpsampleDynamicResolutionThunkLayout();
    ~BSImagespaceShaderISUpsampleDynamicResolutionThunkLayout() override;
};
}
