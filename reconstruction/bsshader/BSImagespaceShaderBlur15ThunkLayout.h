// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderBlur15: EXE_RTTI
// BSImagespaceShaderBlur15ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderBlur15ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderBlur15ThunkLayout();
    ~BSImagespaceShaderBlur15ThunkLayout() override;
};
}
