// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; observed accesses and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf164b0 NiSpotLight::ctor
// Adapted bodies: none
#include "NiSpotLight_f164b0.h"

NiSpotLight::NiSpotLight() :
    m_kWorldDir(1.0f, 0.0f, 0.0f),
    m_fOuterSpotAngle(0.0f),
    m_fInnerSpotAngle(0.0f),
    m_fSpotExponent(1.0f)
{}
