// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderWaterBlendHeightmaps: EXE_RTTI
// BSImagespaceShaderWaterBlendHeightmapsThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderWaterBlendHeightmapsThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderWaterBlendHeightmapsThunkLayout();
    ~BSImagespaceShaderWaterBlendHeightmapsThunkLayout() override;
};
}
