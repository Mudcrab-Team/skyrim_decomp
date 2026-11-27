// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xfd8c50 BSWindModifier::SaveBinary
// Adapted bodies: none
#include "BSWindModifier_fd8c50.h"

void BSWindModifier::SaveBinary(NiStream& a_stream)
{
    NiPSysModifier::SaveBinary(a_stream);

    StreamWriter* writer = a_stream.unk2A0;
    uint32_t sizes = 4;
    writer->unk08 += writer->Write(writer, &unk30, 4, &sizes, 1);
}
