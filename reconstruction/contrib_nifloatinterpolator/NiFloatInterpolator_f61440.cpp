// Source exposure: mixed (pinned-image observations; community stream declarations and helper).
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf61440 NiFloatInterpolator::SaveBinary
// Adapted bodies: none
#include "NiFloatInterpolator_f61440.h"

void NiFloatInterpolator::SaveBinary(NiStream& stream)
{
    NiKeyBasedInterpolator::SaveBinary(stream);
    // The component-size local is scoped to the write so the link-id call that follows is a tail call.
    {
        std::uint32_t componentSize = sizeof(floatValue);
        NiBinaryStream* output = stream.oStr;
        output->_absoluteCurrentPos += output->_writeFn(output, &floatValue, sizeof(floatValue), &componentSize, 1);
    }
    stream.SaveLinkID(floatData);
}
