// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderISSAORawAONoTemporal: EXE_RTTI
// BSImagespaceShaderISSAORawAONoTemporalThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISSAORawAONoTemporalThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISSAORawAONoTemporalThunkLayout();
    ~BSImagespaceShaderISSAORawAONoTemporalThunkLayout() override;
};
}
