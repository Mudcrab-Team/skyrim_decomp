// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// BSImagespaceShaderReflectionsRayTracing: EXE_RTTI
// BSImagespaceShaderReflectionsRayTracingThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Origin: shader-destructor-adjustor v1
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderReflectionsRayTracingThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderReflectionsRayTracingThunkLayout();
    ~BSImagespaceShaderReflectionsRayTracingThunkLayout() override;
};
}
