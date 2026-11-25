// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xefcd80 (gamebryo/nimain/BSGeometry_efcd80): source copied, names replaced by placeholders. Loose twin: constants differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x10b7f60 Owner10b7f60::Function10b7f60
#include "Owner10b7f60.h"

// guess: same compiled code as matched 0xefcd80 apart from relocated fields; its role here is not established.
void Owner10b7f60::Function10b7f60(void* a_dest)
{
    uint32_t elemSize = 48;
    Sink* out = sink;
    out->unk08 += out->unk10(out, a_dest, 48, &elemSize, 1);
}
