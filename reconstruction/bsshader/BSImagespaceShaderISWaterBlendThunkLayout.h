// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISWaterBlend: EXE_RTTI
// BSImagespaceShaderISWaterBlendThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISWaterBlendThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISWaterBlendThunkLayout();
    ~BSImagespaceShaderISWaterBlendThunkLayout() override;
};
}
