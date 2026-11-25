// Source exposure: mixed (pinned image and CommonLibSSE-NG).
// Code origin: original reconstruction using the family generator and community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSSceneGraph: EXE_RTTI
// GetNearDistance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// nearDistance: GUESS(low); stand-in for the display setting value.
// Adapted bodies: none
#pragma once

extern float nearDistance;

class BSSceneGraph
{
public:
    virtual float GetNearDistance();
};
