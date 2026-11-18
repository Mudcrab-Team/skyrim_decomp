// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderBrightPassBlur9: EXE_RTTI
// BSImagespaceShaderBrightPassBlur9ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderBrightPassBlur9ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderBrightPassBlur9ThunkLayout();
    ~BSImagespaceShaderBrightPassBlur9ThunkLayout() override;
};
}
