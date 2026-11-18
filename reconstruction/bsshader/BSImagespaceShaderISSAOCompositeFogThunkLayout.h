// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISSAOCompositeFog: EXE_RTTI
// BSImagespaceShaderISSAOCompositeFogThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISSAOCompositeFogThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISSAOCompositeFogThunkLayout();
    ~BSImagespaceShaderISSAOCompositeFogThunkLayout() override;
};
}
