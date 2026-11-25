// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: body adapted from the sibling function below; offsets and slots checked against the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementPlannerAgentWarp.cpp:110
// 0x7a9dd0 MovementPlannerAgentWarp::SaveGame
#include "MovementPlannerAgentWarp_7a9dd0.h"

void MovementPlannerAgentWarp::SaveGame(BSPathingStreamWrite& a_stream) const
{
    LastFailureLocation.Write(a_stream);
    WarpLocation.Write(a_stream);
    a_stream.DoWrite(fWarpTimer);
    a_stream.DoWriteNumericID(pActor ? pActor->iFormID : 0);
    a_stream.DoWrite(eState);
    a_stream.DoWrite(uiPathFailureCount);
}
