// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderDepthOfFieldFogged: EXE_RTTI
// BSImagespaceShaderDepthOfFieldFoggedThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderDepthOfFieldFoggedThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderDepthOfFieldFoggedThunkLayout();
    ~BSImagespaceShaderDepthOfFieldFoggedThunkLayout() override;
};
}
