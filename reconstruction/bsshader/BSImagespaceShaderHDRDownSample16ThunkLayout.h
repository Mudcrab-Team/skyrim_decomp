// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderHDRDownSample16: EXE_RTTI
// BSImagespaceShaderHDRDownSample16ThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderHDRDownSample16ThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderHDRDownSample16ThunkLayout();
    ~BSImagespaceShaderHDRDownSample16ThunkLayout() override;
};
}
