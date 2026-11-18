// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderWaterFlow: EXE_RTTI
// BSImagespaceShaderWaterFlowThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderWaterFlowThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderWaterFlowThunkLayout();
    ~BSImagespaceShaderWaterFlowThunkLayout() override;
};
}
