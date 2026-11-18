// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISSAOBlurH: EXE_RTTI
// BSImagespaceShaderISSAOBlurHThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISSAOBlurHThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISSAOBlurHThunkLayout();
    ~BSImagespaceShaderISSAOBlurHThunkLayout() override;
};
}
