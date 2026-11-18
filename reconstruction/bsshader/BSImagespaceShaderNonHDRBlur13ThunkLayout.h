// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderNonHDRBlur13: EXE_RTTI
// BSImagespaceShaderNonHDRBlur13ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderNonHDRBlur13ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderNonHDRBlur13ThunkLayout();
    ~BSImagespaceShaderNonHDRBlur13ThunkLayout() override;
};
}
