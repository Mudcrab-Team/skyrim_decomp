// Source exposure: mixed (community declarations; local target observations; sibling symbol facts).
// Code origin: original; local target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf161b0 NiSpotLight::LoadBinary
// Adapted bodies: none
#include "NiSpotLight_f161b0.h"

// ReadFloat: GUESS(low); raw scalar read with stream position accounting.
static void ReadFloat(NiBinaryStream* input, float& value)
{
    std::uint32_t size = sizeof(value);
    input->_absoluteCurrentPos += input->_readFn(input, &value, size, &size, 1);
}

// Loads the base light and the three spotlight scalars in stream order.
void NiSpotLight::LoadBinary(NiStream& stream)
{
    NiPointLight::LoadBinary(stream);
    ReadFloat(stream.iStr, m_fOuterSpotAngle);
    ReadFloat(stream.iStr, m_fInnerSpotAngle);
    ReadFloat(stream.iStr, m_fSpotExponent);
}
