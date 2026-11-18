// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderWorldMap: EXE_RTTI
// BSImagespaceShaderWorldMapThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderWorldMapThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderWorldMapThunkLayout();
    ~BSImagespaceShaderWorldMapThunkLayout() override;
};
}
