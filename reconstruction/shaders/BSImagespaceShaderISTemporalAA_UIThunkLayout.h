// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISTemporalAA_UI: EXE_RTTI
// BSImagespaceShaderISTemporalAA_UIThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISTemporalAA_UIThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISTemporalAA_UIThunkLayout();
    ~BSImagespaceShaderISTemporalAA_UIThunkLayout() override;
};
}
