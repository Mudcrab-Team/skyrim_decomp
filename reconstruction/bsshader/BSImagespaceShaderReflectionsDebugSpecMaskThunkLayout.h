// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderReflectionsDebugSpecMask: EXE_RTTI
// BSImagespaceShaderReflectionsDebugSpecMaskThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderReflectionsDebugSpecMaskThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderReflectionsDebugSpecMaskThunkLayout();
    ~BSImagespaceShaderReflectionsDebugSpecMaskThunkLayout() override;
};
}
