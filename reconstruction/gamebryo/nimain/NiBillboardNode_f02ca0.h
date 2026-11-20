// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBillboardNode: EXE_RTTI
// CopyMembers, CopyNodeMembers, mode: GUESS(low)
// NiObject::LoadBinary, NiObject::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiNode_ee1560.h"

class NiBillboardNode : public NiNode
{
public:
    void CopyMembers(NiBillboardNode* dest);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;

private:
    std::uint16_t mode;
};
