// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISMinify: EXE_RTTI
// BSImagespaceShaderISMinifyThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISMinifyThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISMinifyThunkLayout();
    ~BSImagespaceShaderISMinifyThunkLayout() override;
};
}
