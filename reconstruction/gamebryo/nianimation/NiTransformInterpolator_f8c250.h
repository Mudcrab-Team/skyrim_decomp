// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTransformInterpolator: EXE_RTTI
// CopyMembers, CopyExtendedState, unknown18, ExtendedTransformState, unknown00, extendedState: GUESS(low)
#pragma once

#include "NiKeyBasedInterpolator_f6e600.h"

struct ExtendedTransformState
{
    std::uint8_t unknown00[0x10];
};

class NiTransformInterpolator : public NiKeyBasedInterpolator
{
public:
    void CopyMembers(NiTransformInterpolator* dest) const;
    void CopyExtendedState(NiTransformInterpolator* dest) const;

private:
    std::uint8_t unknown18[0x30];
    ExtendedTransformState extendedState;
};
