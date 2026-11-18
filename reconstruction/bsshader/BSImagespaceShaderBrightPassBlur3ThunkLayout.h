// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderBrightPassBlur3: EXE_RTTI
// BSImagespaceShaderBrightPassBlur3ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderBrightPassBlur3ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderBrightPassBlur3ThunkLayout();
    ~BSImagespaceShaderBrightPassBlur3ThunkLayout() override;
};
}
