// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderNonHDRBlur3: EXE_RTTI
// BSImagespaceShaderNonHDRBlur3ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderNonHDRBlur3ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderNonHDRBlur3ThunkLayout();
    ~BSImagespaceShaderNonHDRBlur3ThunkLayout() override;
};
}
