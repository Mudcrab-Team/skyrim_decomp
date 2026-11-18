// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderWaterDisplacementNormals: EXE_RTTI
// BSImagespaceShaderWaterDisplacementNormalsThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderWaterDisplacementNormalsThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderWaterDisplacementNormalsThunkLayout();
    ~BSImagespaceShaderWaterDisplacementNormalsThunkLayout() override;
};
}
