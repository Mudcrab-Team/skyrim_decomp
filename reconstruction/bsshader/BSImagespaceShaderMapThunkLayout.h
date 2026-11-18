// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderMap: EXE_RTTI
// BSImagespaceShaderMapThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderMapThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderMapThunkLayout();
    ~BSImagespaceShaderMapThunkLayout() override;
};
}
