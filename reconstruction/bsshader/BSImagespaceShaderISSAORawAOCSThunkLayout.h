// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISSAORawAOCS: EXE_RTTI
// BSImagespaceShaderISSAORawAOCSThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISSAORawAOCSThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISSAORawAOCSThunkLayout();
    ~BSImagespaceShaderISSAORawAOCSThunkLayout() override;
};
}
