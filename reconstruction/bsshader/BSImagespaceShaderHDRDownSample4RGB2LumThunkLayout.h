// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderHDRDownSample4RGB2Lum: EXE_RTTI
// BSImagespaceShaderHDRDownSample4RGB2LumThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderHDRDownSample4RGB2LumThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderHDRDownSample4RGB2LumThunkLayout();
    ~BSImagespaceShaderHDRDownSample4RGB2LumThunkLayout() override;
};
}
