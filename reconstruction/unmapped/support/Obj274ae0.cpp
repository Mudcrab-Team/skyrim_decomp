// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x274ae0 Obj274ae0::Function274ae0
// Adapted bodies: none
#include "Obj274ae0.h"

// Recursively copies the global default color into matching shader properties on geometry children.
void Obj274ae0::Function274ae0()
{
    for (std::uint32_t i = 0; i < childCount; ++i) {
        Obj274ae0* child = children[i];
        if (!child) {
            continue;
        }
        if (child->AsNode()) {
            child->Function274ae0();
        } else if (child->AsGeometry()) {
            ShaderProp274ae0* prop = child->shaderProp;
            if (prop && prop->GetRTTI() == &g_shaderRtti274ae0) {
                *prop->colorF0 = g_defaultColor274ae0;
            }
        }
    }
}
