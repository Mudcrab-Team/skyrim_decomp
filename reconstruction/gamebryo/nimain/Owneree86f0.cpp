// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xefcd80 (gamebryo/nimain/BSGeometry_efcd80): source copied, names replaced by placeholders. Loose twin: constants differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0xee86f0 Owneree86f0::Functionee86f0
#include "Owneree86f0.h"

// guess: same compiled code as matched 0xefcd80 apart from relocated fields; its role here is not established.
void Owneree86f0::Functionee86f0(void* a_dest)
{
    uint32_t elemSize = 1;
    Sink* out = sink;
    out->unk08 += out->unk10(out, a_dest, 1, &elemSize, 1);
}
