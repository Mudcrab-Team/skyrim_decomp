// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISSnowSSS: EXE_RTTI
// BSImagespaceShaderISSnowSSSThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISSnowSSSThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISSnowSSSThunkLayout();
    ~BSImagespaceShaderISSnowSSSThunkLayout() override;
};
}
