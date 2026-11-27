// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: adapted from CommonLibSSE-NG (inline body moved out of line), checked against the pinned game build.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GMatrix2D, GMatrix2D::SetIdentity, GMatrix2D::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class GMatrix2D
{
public:
    void SetIdentity();

    float data[2][3];  // 00
};
static_assert(sizeof(GMatrix2D) == 0x18, "GMatrix2D size");
