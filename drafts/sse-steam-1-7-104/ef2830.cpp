// Near miss: 1.0 alignment distance | register-schedule
// Exposure detail: (community names; pinned-image observations).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xef2830 NiAlphaProperty::LoadBinary

#include "include/ef2830/NiAlphaProperty_ef2830.h"
void NiAlphaProperty::LoadBinary(NiStream& stream)
{
    NiProperty::LoadBinary(stream);
    {
        std::uint32_t size = 2;
        stream.input->Read(&flags, 2, &size, 1);
    }
    {
        std::uint32_t size = 1;
        stream.input->Read(&alphaTestRef, 1, &size, 1);
    }
}
