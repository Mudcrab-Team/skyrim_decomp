// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderHDRDownSample16LightAdapt: EXE_RTTI
// BSImagespaceShaderHDRDownSample16LightAdaptThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderHDRDownSample16LightAdaptThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderHDRDownSample16LightAdaptThunkLayout();
    ~BSImagespaceShaderHDRDownSample16LightAdaptThunkLayout() override;
};
}
