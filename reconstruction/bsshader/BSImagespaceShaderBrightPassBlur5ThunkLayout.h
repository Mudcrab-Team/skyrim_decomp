// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderBrightPassBlur5: EXE_RTTI
// BSImagespaceShaderBrightPassBlur5ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderBrightPassBlur5ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderBrightPassBlur5ThunkLayout();
    ~BSImagespaceShaderBrightPassBlur5ThunkLayout() override;
};
}
