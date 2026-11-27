// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf758d0 NiBoolInterpolator::SaveBinary
// Adapted bodies: none
#include "NiBoolInterpolator_f758d0.h"
void NiBoolInterpolator::SaveBinary(NiStream& stream)
{
    NiKeyBasedInterpolator::SaveBinary(stream);
    {
        std::uint32_t componentSize = 1;
        NiBinaryStream* output = stream.oStr;
        output->_absoluteCurrentPos += output->_writeFn(output, &m_bBoolValue, 1, &componentSize, 1);
    }
    stream.SaveLinkID(m_spBoolData);
}
