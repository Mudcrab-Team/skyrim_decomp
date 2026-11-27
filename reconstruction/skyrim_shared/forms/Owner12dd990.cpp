// Source exposure: mixed. Drafted from local instruction listings of the pinned image.
// Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x26b3e0 (skyrim_shared/forms/TESEffectShader): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x12dd990 Owner12dd990::InitializeData
#include "Owner12dd990.h"

// guess: same compiled code as matched 0x26b3e0 apart from relocated fields; its role here is not established.
// CallInitialize12dd990: GUESS(low) STANDIN
void CallInitialize12dd990(EffectShaderData* object);

void Owner12dd990::InitializeData()
{
    CallInitialize12dd990(&data);
}
