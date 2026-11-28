// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x191fa0 Obj191fa0::CopyFrom
// Adapted bodies: none.
#include "Obj191fa0.h"

// Copies the handle, six float fields, and trailing byte from a_src into this object.
void Obj191fa0::CopyFrom(const Obj191fa0* a_src)
{
    handle = a_src->handle;
    unk04 = a_src->unk04;
    unk08 = a_src->unk08;
    unk0C = a_src->unk0C;
    unk10 = a_src->unk10;
    unk14 = a_src->unk14;
    unk18 = a_src->unk18;
    unk1C = a_src->unk1C;
}
