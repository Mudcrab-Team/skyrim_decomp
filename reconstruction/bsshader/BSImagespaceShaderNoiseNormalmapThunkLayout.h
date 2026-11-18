// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderNoiseNormalmap: EXE_RTTI
// BSImagespaceShaderNoiseNormalmapThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderNoiseNormalmapThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderNoiseNormalmapThunkLayout();
    ~BSImagespaceShaderNoiseNormalmapThunkLayout() override;
};
}
