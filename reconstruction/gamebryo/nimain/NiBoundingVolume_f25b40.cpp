// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf25b40 NiBoundingVolume::SaveBinary
// Adapted bodies: none
#include "NiBoundingVolume_f25b40.h"

void NiBoundingVolume::SaveBinary(NiStream& stream)
{
    auto type = GetVolumeType();
    auto* output = stream.oStr;
    std::uint32_t width = sizeof(type);
    const auto written = output->_writeFn(output, &type, sizeof(type), &width, 1);
    output->_absoluteCurrentPos += written;
}
