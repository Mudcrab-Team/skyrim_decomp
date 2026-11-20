// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderBlur5: EXE_RTTI
// BSImagespaceShaderBlur5ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderBlur5ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderBlur5ThunkLayout();
    ~BSImagespaceShaderBlur5ThunkLayout() override;
};
}
