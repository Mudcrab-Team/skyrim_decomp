// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderCopy: EXE_RTTI
// BSImagespaceShaderCopyThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderCopyThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderCopyThunkLayout();
    ~BSImagespaceShaderCopyThunkLayout() override;
};
}
