// Source exposure: mixed. Drafted from local instruction listings of the pinned image.
// Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x26b3e0 (skyrim_shared/forms/TESEffectShader): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x3feda0 Owner3feda0::InitializeData
#include "Owner3feda0.h"

// guess: same compiled code as matched 0x26b3e0 apart from relocated fields; its role here is not established.
// CallInitialize3feda0: GUESS(low) STANDIN
void CallInitialize3feda0(EffectShaderData* object);

void Owner3feda0::InitializeData()
{
    CallInitialize3feda0(&data);
}
