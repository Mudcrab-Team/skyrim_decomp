// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderBrightPassBlur11: EXE_RTTI
// BSImagespaceShaderBrightPassBlur11ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderBrightPassBlur11ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderBrightPassBlur11ThunkLayout();
    ~BSImagespaceShaderBrightPassBlur11ThunkLayout() override;
};
}
