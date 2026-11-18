// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISSILComposite: EXE_RTTI
// BSImagespaceShaderISSILCompositeThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISSILCompositeThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISSILCompositeThunkLayout();
    ~BSImagespaceShaderISSILCompositeThunkLayout() override;
};
}
