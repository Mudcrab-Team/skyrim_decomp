// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderApplyReflections: EXE_RTTI
// BSImagespaceShaderApplyReflectionsThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderApplyReflectionsThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderApplyReflectionsThunkLayout();
    ~BSImagespaceShaderApplyReflectionsThunkLayout() override;
};
}
