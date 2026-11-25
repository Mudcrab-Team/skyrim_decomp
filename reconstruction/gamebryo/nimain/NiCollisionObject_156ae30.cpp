// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed (community headers; pinned-image observations).
// Code origin: original; pinned-image observations and community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCollisionObject::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCollisionObject::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x156ae30 NiCollisionObject::SaveBinary
// Adapted bodies: none
#include "NiCollisionObject_156ae30.h"

void NiCollisionObject::SaveBinary(NiStream& stream)
{
    NiObject::SaveBinary(stream);
    stream.SaveLinkID(sceneObject);
}
