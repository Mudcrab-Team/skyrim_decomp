// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderRefraction: EXE_RTTI
// BSImagespaceShaderRefractionThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderRefractionThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderRefractionThunkLayout();
    ~BSImagespaceShaderRefractionThunkLayout() override;
};
}
