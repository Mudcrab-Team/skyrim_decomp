// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderNonHDRBlur11: EXE_RTTI
// BSImagespaceShaderNonHDRBlur11ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderNonHDRBlur11ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderNonHDRBlur11ThunkLayout();
    ~BSImagespaceShaderNonHDRBlur11ThunkLayout() override;
};
}
