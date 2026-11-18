// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderWaterDisplacementTexOffset: EXE_RTTI
// BSImagespaceShaderWaterDisplacementTexOffsetThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderWaterDisplacementTexOffsetThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderWaterDisplacementTexOffsetThunkLayout();
    ~BSImagespaceShaderWaterDisplacementTexOffsetThunkLayout() override;
};
}
