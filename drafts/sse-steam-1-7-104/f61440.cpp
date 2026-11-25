// Near miss: 3.0 alignment distance | control-flow
// Exposure detail: (pinned-image observations; community stream declarations and helper).
// Source exposure: mixed
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xf61440 NiFloatInterpolator::SaveBinary

#include "include/f61440/NiFloatInterpolator_f61440.h"

void NiFloatInterpolator::SaveBinary(NiStream& stream)
{
    NiKeyBasedInterpolator::SaveBinary(stream);
    std::uint32_t componentSize = sizeof(floatValue);
    NiBinaryStream* output = stream.oStr;
    output->_absoluteCurrentPos += output->_writeFn(output, &floatValue, sizeof(floatValue), &componentSize, 1);
    stream.SaveLinkID(floatData);
}
