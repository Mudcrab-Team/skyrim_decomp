// CI hash: 0xfc0dc0 ?Functionfc0dc0@Unkfc0dc0@@QEAAXPEAV1@@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unkfc0dc0: STANDIN GUESS(low)
// Unkfc0dc0::Functionfc0dc0: GUESS(low)
// Unkfc0dc0::unk30, Unkfc0dc0::unk38, Unkfc0dc0::unk3c, Unkfc0dc0::unk40, Unkfc0dc0::unk44, Unkfc0dc0::unk48: GUESS(low)
// 0xfc0dc0 Unkfc0dc0::Functionfc0dc0
#include "Unkfc0dc0_fc0dc0.h"

// Copy the emitter base and the observed derived fields.
void Unkfc0dc0::Functionfc0dc0(Unkfc0dc0* target)
{
    CopyEmitterBase(this, target);
    target->unk30 = unk30;
    target->unk38 = unk38;
    target->unk3c = unk3c;
    target->unk40 = unk40;
    target->unk44 = unk44;
    target->unk48 = unk48;
}
