// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderCopyCustomViewport: EXE_RTTI
// BSImagespaceShaderCopyCustomViewportThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderCopyCustomViewportThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderCopyCustomViewportThunkLayout();
    ~BSImagespaceShaderCopyCustomViewportThunkLayout() override;
};
}
