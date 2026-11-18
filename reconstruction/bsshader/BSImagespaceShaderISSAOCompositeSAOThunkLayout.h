// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISSAOCompositeSAO: EXE_RTTI
// BSImagespaceShaderISSAOCompositeSAOThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISSAOCompositeSAOThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISSAOCompositeSAOThunkLayout();
    ~BSImagespaceShaderISSAOCompositeSAOThunkLayout() override;
};
}
