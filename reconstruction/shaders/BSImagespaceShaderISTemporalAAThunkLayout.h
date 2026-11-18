// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISTemporalAA: EXE_RTTI
// BSImagespaceShaderISTemporalAAThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISTemporalAAThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISTemporalAAThunkLayout();
    ~BSImagespaceShaderISTemporalAAThunkLayout() override;
};
}
