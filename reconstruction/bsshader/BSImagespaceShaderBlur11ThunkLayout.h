// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderBlur11: EXE_RTTI
// BSImagespaceShaderBlur11ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderBlur11ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderBlur11ThunkLayout();
    ~BSImagespaceShaderBlur11ThunkLayout() override;
};
}
