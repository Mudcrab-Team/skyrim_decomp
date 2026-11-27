// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xefcd80 (gamebryo/nimain/BSGeometry_efcd80): source copied, names replaced by placeholders. Loose twin: constants differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x1088310 Owner1088310::Function1088310
#include "Owner1088310.h"

// guess: same compiled code as matched 0xefcd80 apart from relocated fields; its role here is not established.
void Owner1088310::Function1088310(void* a_dest)
{
    uint32_t elemSize = 64;
    Sink* out = sink;
    out->unk08 += out->unk10(out, a_dest, 64, &elemSize, 1);
}
