// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderNonHDRBlur15: EXE_RTTI
// BSImagespaceShaderNonHDRBlur15ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderNonHDRBlur15ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderNonHDRBlur15ThunkLayout();
    ~BSImagespaceShaderNonHDRBlur15ThunkLayout() override;
};
}
