// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xfd8c50 (gamebryo/nianimation/BSWindModifier_fd8c50): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x1001910 Owner1001910::SaveBinary
#include "Owner1001910.h"

// guess: same compiled code as matched 0xfd8c50 apart from relocated fields; its role here is not established.
void Owner1001910::SaveBinary(NiStream& a_stream)
{
    NiPSysModifier::SaveBinary(a_stream);

    StreamWriter* writer = a_stream.unk2A0;
    uint32_t sizes = 4;
    writer->unk08 += writer->Write(writer, &unk30, 4, &sizes, 1);
}
