// CI hash: 0x15550d0 ?Function15550d0@Unk15550d0@@QEAAXXZ
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk15550d0: STANDIN GUESS(low)
// Unk15550d0::Function15550d0: GUESS(low)
// Unk15550d0::value, Unk15550d0::index, Unk15550d0::context, SharedRef: GUESS(low)
// 0x15550d0 Unk15550d0::Function15550d0
#include "Unk15550d0_15550d0.h"

// Update shared ownership and release the displaced reference.
void Unk15550d0::Function15550d0()
{
    auto* old = value;
    if (old) { value = nullptr; if (old->references.fetch_sub(1) == 1) old->Destroy(); }
    index = ~std::uint64_t{0};
    context = nullptr;
}
