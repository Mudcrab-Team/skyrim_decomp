// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderGreyScale: EXE_RTTI
// BSImagespaceShaderGreyScaleThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderGreyScaleThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderGreyScaleThunkLayout();
    ~BSImagespaceShaderGreyScaleThunkLayout() override;
};
}
