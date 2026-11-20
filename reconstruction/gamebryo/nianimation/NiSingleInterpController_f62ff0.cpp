// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xeebee0 NiTimeController::SetNext
// 0xf62ff0 NiSingleInterpController::GetInterpolatorIndexFx
// 0xf630b0 NiSingleInterpController::GuaranteeTimeRange
// 0xf63140 NiSingleInterpController::TargetIsRequiredType
#include "NiSingleInterpController_f62ff0.h"

// invalidInterpolatorIndex: GUESS(low); returned when the target name differs.
extern const std::uint16_t invalidInterpolatorIndex;

void NiTimeController::SetNext(NiTimeController* successor)
{
    auto* previous = next;
    if (previous != successor) {
        if (successor) {
            // Retain the new controller before storing the link.
            _InterlockedIncrement(reinterpret_cast<volatile long*>(&successor->_refCount));
        }
        next = successor;
        // Release the old controller through its atomic reference count.
        if (previous && _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&previous->_refCount), -1) == 1) {
            return previous->DeleteThis();
        }
    }
}

std::uint16_t NiSingleInterpController::GetInterpolatorIndexFx(const BSFixedString& id) const
{
    return target->name.text == id.text ? 0 : invalidInterpolatorIndex;
}

void NiSingleInterpController::GuaranteeTimeRange(float start, float end)
{
    if (interpolator) {
        return interpolator->GuaranteeTimeRange(start, end);
    }
}

bool NiSingleInterpController::TargetIsRequiredType() const
{
    return IsValidTarget(target);
}
