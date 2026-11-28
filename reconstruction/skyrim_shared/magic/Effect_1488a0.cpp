// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build, with the cited accessors.
// Adapted bodies: Effect::GetMagnitude follows CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/E/Effect.cpp:22 (MIT).
// 0x1488a0 Effect::GetMagnitude
// 0x1489e0 Effect::IsUsageMonitorEffect
#include "Effect_1488a0.h"

// The PDB calls this EffectItem::GetMagnitude; CommonLib's Effect is the same record.
float Effect::GetMagnitude() const
{
    if (baseEffect->data.IsFlagSet(EffectSetting::EffectSettingData::kNoMagnitudeBit)) {
        return 0.0f;
    }
    return effectItem.magnitude;
}

// True when this effect's base effect is the usage-monitor effect.
bool Effect::IsUsageMonitorEffect() const
{
    const EffectSetting* setting = baseEffect;
    return setting == Function14d670();
}
