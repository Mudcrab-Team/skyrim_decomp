// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: reconstruction using cited declarations and stand-in layouts; see Adapted bodies.
// Adapted bodies: NiBinaryStream::WriteByte, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfdd5f0 BSRangeNode::SaveBinary
#include "BSRangeNode_fdd5f0.h"

// Saves the base node state and the three range-node byte fields.
// The CrashLogger name carries an address suffix, which is dropped here.
void BSRangeNode::SaveBinary(NiStream& stream)
{
    NiNode::SaveBinary(stream);
    stream.oStr->WriteByte(first);
    stream.oStr->WriteByte(second);
    stream.oStr->WriteByte(mode);
}
