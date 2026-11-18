// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISUnderwaterMask: EXE_RTTI
// BSImagespaceShaderISUnderwaterMaskThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISUnderwaterMaskThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISUnderwaterMaskThunkLayout();
    ~BSImagespaceShaderISUnderwaterMaskThunkLayout() override;
};
}
