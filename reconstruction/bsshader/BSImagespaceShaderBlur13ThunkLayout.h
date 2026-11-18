// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderBlur13: EXE_RTTI
// BSImagespaceShaderBlur13ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderBlur13ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderBlur13ThunkLayout();
    ~BSImagespaceShaderBlur13ThunkLayout() override;
};
}
