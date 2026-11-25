// Source exposure: mixed (community declarations; local target observations; sibling symbol facts).
// Code origin: original; local target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfc0f70 NiPSysFieldModifier::SaveBinary
// Adapted bodies: none
#include "NiPSysFieldModifier_fc0f70.h"

// WriteScalar: GUESS(low); raw value write with stream position accounting.
template <class T>
static void WriteScalar(NiBinaryStream* output, const T& value)
{
    std::uint32_t size = sizeof(value);
    output->_absoluteCurrentPos += output->_writeFn(output, &value, size, &size, 1);
}

// Saves the base modifier, linked field object and field parameters.
void NiPSysFieldModifier::SaveBinary(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    stream.SaveLinkID(m_pkFieldObj);
    WriteScalar(stream.oStr, m_fMagnitude);
    WriteScalar(stream.oStr, m_fAttenuation);
    std::uint8_t useMaxDistance = m_bUseMaxDistance;
    WriteScalar(stream.oStr, useMaxDistance);
    WriteScalar(stream.oStr, m_fMaxDistance);
}
