// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderNonHDRBlur9: EXE_RTTI
// BSImagespaceShaderNonHDRBlur9ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderNonHDRBlur9ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderNonHDRBlur9ThunkLayout();
    ~BSImagespaceShaderNonHDRBlur9ThunkLayout() override;
};
}
