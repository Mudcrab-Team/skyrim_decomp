// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x152ce50 BSWaterShaderProperty::ForEachTexture
// Adapted bodies: none
#include "BSWaterShaderProperty_152ce50.h"

std::int32_t BSWaterShaderProperty::ForEachTexture(ForEachVisitor& a_visitor)
{
    std::int32_t result = 1;
    if (material) {
        result = static_cast<std::int32_t>(a_visitor.Accept(material->unk40));
        if (result <= 0) {
            return result;
        }
        result = static_cast<std::int32_t>(a_visitor.Accept(material->GetTexture2()));
        if (result <= 0) {
            return result;
        }
        result = static_cast<std::int32_t>(a_visitor.Accept(material->GetTexture3()));
    }
    return result;
}
