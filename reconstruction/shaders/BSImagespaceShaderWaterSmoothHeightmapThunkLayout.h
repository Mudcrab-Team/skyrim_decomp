// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderWaterSmoothHeightmap: EXE_RTTI
// BSImagespaceShaderWaterSmoothHeightmapThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderWaterSmoothHeightmapThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderWaterSmoothHeightmapThunkLayout();
    ~BSImagespaceShaderWaterSmoothHeightmapThunkLayout() override;
};
}
