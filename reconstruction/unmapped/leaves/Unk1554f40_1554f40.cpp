// CI hash: 0x1554f40 ?Function1554f40@Unk1554f40@@QEAAXI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk1554f40: STANDIN GUESS(low)
// Unk1554f40::Function1554f40: GUESS(low)
// Unk1554f40::value, Unk1554f40::tag, Unk1554f40::index, SharedRef: GUESS(low)
// 0x1554f40 Unk1554f40::Function1554f40
#include "Unk1554f40_1554f40.h"

// Update shared ownership and release the displaced reference.
void Unk1554f40::Function1554f40(std::uint32_t newTag)
{
    tag = newTag;
    auto* old = value;
    if (old) { value = nullptr; if (old->references.fetch_sub(1) == 1) old->Destroy(); }
    index = ~std::uint32_t{0};
}
