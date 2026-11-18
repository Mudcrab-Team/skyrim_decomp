// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderDepthOfFieldMaskedFogged: EXE_RTTI
// BSImagespaceShaderDepthOfFieldMaskedFoggedThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderDepthOfFieldMaskedFoggedThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderDepthOfFieldMaskedFoggedThunkLayout();
    ~BSImagespaceShaderDepthOfFieldMaskedFoggedThunkLayout() override;
};
}
