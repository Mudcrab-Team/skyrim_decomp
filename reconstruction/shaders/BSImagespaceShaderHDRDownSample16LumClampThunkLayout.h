// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderHDRDownSample16LumClamp: EXE_RTTI
// BSImagespaceShaderHDRDownSample16LumClampThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderHDRDownSample16LumClampThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderHDRDownSample16LumClampThunkLayout();
    ~BSImagespaceShaderHDRDownSample16LumClampThunkLayout() override;
};
}
