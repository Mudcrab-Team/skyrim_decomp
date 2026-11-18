// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderCopyScaleBias: EXE_RTTI
// BSImagespaceShaderCopyScaleBiasThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderCopyScaleBiasThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderCopyScaleBiasThunkLayout();
    ~BSImagespaceShaderCopyScaleBiasThunkLayout() override;
};
}
