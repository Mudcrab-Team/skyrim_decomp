// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderHDRTonemapBlendCinematic: EXE_RTTI
// BSImagespaceShaderHDRTonemapBlendCinematicThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderHDRTonemapBlendCinematicThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderHDRTonemapBlendCinematicThunkLayout();
    ~BSImagespaceShaderHDRTonemapBlendCinematicThunkLayout() override;
};
}
