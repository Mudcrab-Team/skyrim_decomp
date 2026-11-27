// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from CommonLibSSE-NG (inline body moved out of line), checked against the pinned game build.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xd03aa0 GMatrix2D::SetIdentity
// Adapted bodies: GMatrix2D::SetIdentity, CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/G/GMatrix2D.h:49 (MIT).
#include "GMatrix2D.h"

void GMatrix2D::SetIdentity()
{
    data[0][0] = 1.0f;
    data[0][1] = 0.0f;
    data[0][2] = 0.0f;
    data[1][0] = 0.0f;
    data[1][1] = 1.0f;
    data[1][2] = 0.0f;
}
