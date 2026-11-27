// Near miss: 2.5 alignment distance | register-schedule
// Exposure detail: (pinned-image observations and public declarations).
// Source exposure: mixed
// Code origin: original hand-written reconstruction; no adapted body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSStandardSoundDef, BGSSoundOutput, BSIAttenuationCharacteristics, outputModel, attenuation, GetMaxDistance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// GetOutputMaxDistance, outputFlags, reserved: GUESS(low); behavior-derived names.
// 0x32c260 BGSStandardSoundDef::GetOutputMaxDistance

#include "include/32c260/BGSStandardSoundDef_32c260.h"
#include <cfloat>
float BGSStandardSoundDef::GetOutputMaxDistance() const
{
    float maxDistance = FLT_MAX;
    if (outputModel) {
        if (outputModel->outputFlags & 1) {
            BSIAttenuationCharacteristics* characteristics = outputModel->attenuation;
            if (characteristics)
                maxDistance = characteristics->GetMaxDistance();
        }
    }
    return maxDistance;
}
