// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISTemporalAA_Water: EXE_RTTI
// BSImagespaceShaderISTemporalAA_WaterThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISTemporalAA_WaterThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISTemporalAA_WaterThunkLayout();
    ~BSImagespaceShaderISTemporalAA_WaterThunkLayout() override;
};
}
