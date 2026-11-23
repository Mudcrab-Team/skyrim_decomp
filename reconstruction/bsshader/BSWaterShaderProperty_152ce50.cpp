// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x152ce50 BSWaterShaderProperty::ForEachTexture
// Adapted bodies: none
#include "BSWaterShaderProperty_152ce50.h"

int BSWaterShaderProperty::ForEachTexture(ForEachVisitor& a_visitor)
{
    int result = 1;
    if (material) {
        result = a_visitor.Accept(material->firstTexture);
        if (result <= 0) return result;
        result = a_visitor.Accept(material->GetSecond());
        if (result <= 0) return result;
        result = a_visitor.Accept(material->GetThird());
    }
    return result;
}
