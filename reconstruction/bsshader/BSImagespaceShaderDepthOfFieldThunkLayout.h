// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderDepthOfField: EXE_RTTI
// BSImagespaceShaderDepthOfFieldThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderDepthOfFieldThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderDepthOfFieldThunkLayout();
    ~BSImagespaceShaderDepthOfFieldThunkLayout() override;
};
}
