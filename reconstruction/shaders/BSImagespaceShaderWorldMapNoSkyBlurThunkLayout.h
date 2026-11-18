// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderWorldMapNoSkyBlur: EXE_RTTI
// BSImagespaceShaderWorldMapNoSkyBlurThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderWorldMapNoSkyBlurThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderWorldMapNoSkyBlurThunkLayout();
    ~BSImagespaceShaderWorldMapNoSkyBlurThunkLayout() override;
};
}
