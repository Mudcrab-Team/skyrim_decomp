// CI hash: 0x148a10 ?Function148a10@Effect@@QEAA_KXZ
// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Effect: GUESS(low)
// Effect::Function148a10: GUESS(low)
// Effect::unk10, Effect::kStep0: GUESS(low)
// 0x148a10 Effect::Function148a10
#include "Effect_148a10.h"

// Read the selected bits of the stored scalar.
std::uint64_t Effect::Function148a10()
{
    return (unk10 + kStep0);
}
