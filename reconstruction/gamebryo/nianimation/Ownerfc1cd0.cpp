// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0xf634d0 (gamebryo/nianimation/NiTransformInterpolator_f634d0): source copied, names replaced by placeholders.
// 0xfc1cd0 Ownerfc1cd0::RegisterStreamables
#include "Ownerfc1cd0.h"
#include "NiStream.h"

// The forwarding callees are declared from their measured use sites.
// RegisterKeyBasedStreamables_fc1cd0, SaveKeyBasedBinary, SaveTransformValue, GuaranteeTransformDataTimeRange: GUESS(low) STANDIN
bool RegisterKeyBasedStreamables_fc1cd0(NiKeyBasedInterpolator& interpolator, NiStream& stream);

// guess: same compiled code as matched 0xf634d0 apart from relocated fields; its role here is not established.
bool Ownerfc1cd0::RegisterStreamables(NiStream& stream)
{
    const bool registered = RegisterKeyBasedStreamables_fc1cd0(*this, stream);
    if (!registered) {
        return registered;
    }
    if (data) {
        data->RegisterStreamables(stream);
    }
    return true;
}
