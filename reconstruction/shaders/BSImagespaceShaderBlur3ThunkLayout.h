// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderBlur3: EXE_RTTI
// BSImagespaceShaderBlur3ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderBlur3ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderBlur3ThunkLayout();
    ~BSImagespaceShaderBlur3ThunkLayout() override;
};
}
