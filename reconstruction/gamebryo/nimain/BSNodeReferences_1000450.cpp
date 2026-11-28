// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: reconstruction using cited declarations and stand-in layouts; see Adapted bodies.
// Adapted bodies: NiBinaryStream::WriteValue, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1000450 BSNodeReferences::SaveBinary
#include "BSNodeReferences_1000450.h"

// Saves the paired parent and node link IDs for each referenced node.
// The CrashLogger name carries an address suffix, which is dropped here.
void BSNodeReferences::SaveBinary(NiStream& stream)
{
    NiObject::SaveBinary(stream);

    std::uint32_t count = nodes._size;
    std::uint32_t linkCount = count * 2;
    stream.oStr->WriteValue(&linkCount);

    for (std::uint32_t i = 0; i < count; ++i)
    {
        NiAVObject* node = nodes._data[i];
        if (node)
        {
            stream.SaveLinkID(node->parent);
            stream.SaveLinkID(node);
        }
    }
}
